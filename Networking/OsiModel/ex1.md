Layer 1 -> Electrical signals that actually transmit data/

Layer 2 -> Data link wraps each frame into a network packet and sends it over the physical link to
			the next switch or router that the computer is connected to. This is essentially the network card.

Layer 3/4 -> The TCP/IP stack breaks the request up into packets (if needed), and sends them out over the data link. It resends packets as
				necessary and manages the rate at wich packets are sent. This is essentially the operating system.

Layer 7, 6 , 5 -> The web browser creates a request and tells the networking stack to sent it to some address.


a. It uses the DNS protocol.
b. Once we established a connection, we send an HTTP GET rquest, once the request is recieved the server will reply with a response.
c. TCP/UDP, 80 8080 443 53
d. IP, src IP and dst IP
e. Next hop is the next closer router a packet can go through. We can see it in the routing table.
f. Ethernet. src MAC and dst MAC.