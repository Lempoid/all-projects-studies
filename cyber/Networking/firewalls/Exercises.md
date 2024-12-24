---
title: Practice iptables.
---
# EX1
Block cnn.com

```bash
iptables -A OUTPUT -p tcp -m string --string "block-me.com" --algo kmp -j REJECT
```

`-A OUTPUT` adds the following rule to the `OUTPUT` chain.

`-m string --string "block-me.com" --algo kmp` tells iptables to look for the string `block-me.com` using the KMP algorithm to match the string X in string S.

`-j REJECT` sends the packet to rejection.

In our case we use cnn.com instead of block-me.com

***Note:***
The change in the iptables won't be permanent and will be restarted upon reboot.

To save permanently: 

```bash
sudo bash -c "iptables-save > /etc/iptables/rules.v4"
```
If you just run `sudo iptables-save > /etc/iptables/rules.v4` you will get an "access denied" message for `rules.v4`.

# EX2
Allow HTTPS traffic only.

```bash
sudo iptables -A OUTPUT -p tcp --dport 80 -m conntrack --ctstate NEW,ESTABLISHED -j DROP
```

```bash
sudo iptables -A OUTPUT -p tcp --dport 443 -m conntrack --ctstate NEW,ESTABLISHED -j ACCEPT
```

```bash
sudo iptables -A INPUT -p tcp --dport 443 -m conntrack -ctstate ESTABLISHED -j ACCEPT
```
`-m conntrack --ctstate`connection tracking of states. Allows traffic based on connection states.

# EX3
Block ping requests.

```bash
sudo iptables -I INPUT -p icmp --icmp-type 8 -j DROP
```
`--icmp-type 8` is echo reply.

# EX4
Allow only one ssh connection at a time.

```bash
iptables -A INPUT -p tcp --dport 22 -m connlimit --max 1 --connlabel 22 -j ACCEPT
```
`-m connlimit --max 1 --connlabel 22` limit to 1 connection and label it with unique 22 identifier.

# EX5
Make ssh on port 500 and allow connection only from specific ip.
Change port in ssh config file by adding Port 500:

```bash
sudo subl /etc/ssh/sshd_config
```

Add rules to iptables:

```bash
sudo iptables -A INPUT -p tcp -s 10.10.1.33 --dport 500 -m conntrack --ctstate NEW,ESTABLISHED -j ACCEPT
sudo iptables -A OUTPUT -p tcp --sport 500 -m conntrack --ctstate ESTABLISHED -j ACCEPT
```

Restart services:
```bash
sudo systemctl stop ssh.service ssh.socket 
sudo systemctl disable ssh.service ssh.socket 
sudo systemctl enable ssh.service ssh.socket 
sudo systemctl start ssh.service ssh.socket

```


# EX6

**Enable IP Forwarding on host**

```bash
sudo nano /etc/sysctl.conf
```

**Modify the line**

```bash
net.ipv4.ip_forward=1
```

**Apply changes**
```bash
sudo sysctl -p
```


**Configure NAT on host**

```bash
sudo iptables -t nat -A POSTROUTING -o wlo1 -j MASQUERADE
```

```bash
sudo iptables -A FORWARD -i vboxnet0 -o wlo1 -j ACCEPT
```

```bash
sudo iptables -A FORWARD -i eth0 -o vboxnet0 -m state --state ESTABLISHED,RELATED -j ACCEPT
```

**Test Internet Access on guest**

```bash
ping 8.8.8.8
```

If doesn't work, check if need to add IP and default gateway to guest interface.
```bash
sudo ip addr add 192.168.57.3/24 dev enp0s3
```

```bash
sudo ip route add default via 192.168.57.1
```

 **b. Run an HTTP Server and Port-Forward**

**Install Apache2 on host**

```bash
sudo apt update
sudo apt install apache2
```


 **Configure Port Forwarding on host**

```bash
sudo iptables -t nat -A PREROUTING -p tcp --dport 80 -j DNAT --to-destination 10.10.1.51:8080
```
`PREROUTING` change a packet before routing
`DNAT --to-destination IP_ADDRESS:PORT` use DNAT to forward from specific port to a specific address and port.


```bash
sudo iptables -A FORWARD -p tcp -d 10.10.1.51 --dport 8080 -m state --state NEW,ESTABLISHED,RELATED -j ACCEPT
```
`FORWARDS -p tcp -d IP_ADDRESS --dport PORT` forwards traffic to destination.
`-m state --state NEW,ESTABLISHED,RELATED` if the connection is in one of those states.


**Verify on guest**
Open browser and try to go to host ip
http://<host_IP>


**c. Block Access to the Guest Server**

**Block Traffic Between Host and Guest, run on guest**


```bash
sudo iptables -A INPUT -s 192.168.57.1 -j DROP
```
Drops every packet coming from IP_ADDRESS (host)


```bash
sudo iptables -A OUTPUT -d 192.168.57.1 -j DROP
```
Drops every packet originating from guest to IP_ADDRESS (host)

**Verify the Block**

```bash
ping 192.168.57.1
```

**d. Enable Browsing Using SSH Tunneling**

**Install OpenSSH Server on guest**

```bash
sudo apt install openssh-server
```

**Establish SSH Tunnel on host**

```bash
ssh -L 8080:localhost:80 lempo2@192.168.57.3
```
Guest user and IP.

**Test Tunnel from host**

In browser http://localhost:8080
