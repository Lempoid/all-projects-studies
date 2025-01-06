---
title: make a ppp connectivity.
source: https://superuser.com/questions/1394053/ppp-connection-to-a-virtualbox-guest
---


***Note:***
I don't have Ethernet cable interface so I used a VM (virtual box)as additional host.

1) Ensure that both socat and ppp are installed on host and guest.
2) Start the VM in host-only mode and allow serial port. It is greyed out because the VM is running.
   ![[Pasted image 20241226082737.png]]

3) On the host, we create a virtual serial port. Keep the terminal open after running the command and open a new terminal tab.

```bash
sudo socat PTY,link=/dev/ttyS14 TCP4-LISTEN:1236
```
We set a virtual serial port which listens over tcp on port 1236.

4) Run pppd to create ppp interface
   
```bash
sudo pppd /dev/ttyS14 115200 192.168.1.1:192.168.1.2 asyncmap 0 proxyarp lock crtscts noauth nodetach
```
We set a ppp through interface ttyS14 with 115200 serial link speed. HostIP  (192.168.1.1) and GuestIP (192.168.1.2) with configuration to lock the interface for that connection only and some other configurations for easier setting up (no authentication for simplicity.).

5) On the guest 
   ```bash
   sudo pppd /dev/ttyS0 115200 asyncmap 0 lock crtscts noauth nodetach
```
6) Check on host and guest ifconfig (or ip addr) for ppp0, each should have its ip  host 192.168.1.1 guest 192.168.1.2

7) Enable ip forwarding on host.

8) Set ip tables on host:
   ```bash
   sudo iptables -A FORWARD -i ppp0 -o wlo1 -j ACCEPT
   sudo iptables -A FORWARD -i wlo1 -o ppp0 -m conntrack --ctstate RELATED, ESTABLISHED -j ACCEPT
   sudo iptables -t nat -A POSTROUTING -o wlo1 -j MASQUERADE
```
9) Set default gateway on guest:
   ```bash
   sudo ip route add default dev ppp0
```
10) After all is set, try pinging host and guest from one another and try to ping 8.8.8.8 from guest.

**MTU**
Mtu can be set in the pppd setup with `sudo pppd ... mtu 1400 ...`, make sure that it is set the same for host and guest to limit fragmantation.
It can be set dynamically with `sudo ifconfig ppp0 mtu 1200`
