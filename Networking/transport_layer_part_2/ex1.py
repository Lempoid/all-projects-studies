"""
Approved by: Ben Bortkevich
Author: Alex Breger
"""

import socket

if _name_ == "_main_":
    target = input("Give IP address: ")
    host = socket.gethostbyname(target)
    print(host)
    list_of_open_ports = []
    for i in range(1,1024):
        my_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        print(my_socket)
        connection = my_socket.connect_ex((host, i))
        print(connection)
        if connection == 0:
            list_of_open_ports.append(i)

        my_socket.close()

    print(list_of_open_ports)