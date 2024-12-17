Continue from ex2

1) Undo all iptables and routing changes on the hosts (the guests still need to know how to route to the defualt gateway)

2) I used FRR (sudo apt isntall frr)

3) configure frr daemon conf. (nano /etc/frr/daemons)

4) restart frr

5) sudo vtysh to configure opsf (the configuration is like router cli)

lempo# conf t
lempo(config)# !
lempo(config)# router ospf
lempo(config-router)# network 10.0.0.1 area 0
Unknown command: network 10.0.0.1 area 0
lempo(config-router)# network 10.0.0.1/30 area 0
lempo(config-router)# network 192.168.57.1/24 area 0
lempo(config-router)# exit
lempo(config)# !
lempo(config)# exit
lempo# write memory 
lempo# exit

6) Now our host uses ospf routing with the interfaces 10.0.0.1/30 192.168.57.1/24

7) When both hosts are configured, ping should go through.