"""
Approved by: Ben Bortkevich
Author: Alex Breger
"""


import socket

if _name_ == "_main_":
    target_ip = input("Give IP address: ")
    target_port = int(input("Give port address: "))
    subnet = "255.255.255.0"
    list_of_open_ips = []

    for i in range(0,256):
        target_ip = target_ip[:target_ip.rfind('.') + 1] + f'{i}'
        my_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        my_socket.settimeout(0.5)
        connection = my_socket.connect_ex((target_ip, target_port))
        print(f"Checking port {target_port} on IP {target_ip}")
        if connection == 0:
            list_of_open_ips.append(target_ip)

        my_socket.close()

    print(list_of_open_ips)