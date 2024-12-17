2 phisical hosts were used instead of nested vms because of hardware limitations. Each host had a vm running on it.
We have H1, H2, G1, G2 for each host guest. We used our original wifi with tunneling to imitate routing.

1) Run the vms G1 and G2 as host only option for the network adapter. 
make sure the networks are different.

2) Ensure that forwarding is enabled on both hosts.

3) Make tunneling between the routrers. (It imitates a common network that the routers communicate on.)

4) Make ping in both direction to ensure tunnelling works.

5) Ensure that g1 sees h1 as a default gateway and that g2 sees h2 as a gateway.

6) Ensure that g1 and g2 route traffic through their respective gateway when the need to send packets to each other arises.

7) Ensure that routers route the packets both ways.

8) check connetion h to g and g to g.