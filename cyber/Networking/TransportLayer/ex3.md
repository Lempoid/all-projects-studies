Running "ifconfig" in terminal gives me wlo1 information which is my wireless network. I see a few IPv6 addresses, 2 public and 1 local.

They were given to me by the DHCPv6 probably.

Run "ping6 ip_v6_address" to get a ping. (I used mac).

Run sudo ip addr add 2001:db8::1/64 dev wlo1

