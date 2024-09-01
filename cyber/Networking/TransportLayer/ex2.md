Run sudo wireshark in terminal.

Choose the network you want to work on

Filter for "tcp" in the filter bar and press enter. This will give all TCP traffic. (TCP, TLS)

Filter for "udp" and press enter. This will give all the udp traffic. (DNS, QUIC, MDNS)

Filter for "not tcp and not udp" and press enter. This will give all the none tcp and udp traffic. (ICMP, ARP)

Filter for "tcp.analysis.keep_alive" to find the keep alive packets which are usually 1 byte of payload. 