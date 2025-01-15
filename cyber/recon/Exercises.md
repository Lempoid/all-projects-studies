1) Install `sudo apt install dnsenum
    run `dnsenum ilrd.co.il`
   dnsenum VERSION:1.2.6

-----   ilrd.co.il   -----


Host's addresses:
__________________

ilrd.co.il.                              5250     IN    A        62.219.91.45


Name Servers:
______________

ns3.dtnt.info.                           14       IN    A        18.237.95.239
ns3.dtnt.info.                           14       IN    A        52.36.225.219
ns1.dtnt.info.                           94       IN    A        62.219.91.139
ns2.dtnt.info.                           94       IN    A        63.32.93.178
ns2.dtnt.info.                           94       IN    A        62.219.91.150
ns2.dtnt.info.                           94       IN    A        63.34.99.163


Mail (MX) Servers:
___________________

alt2.aspmx.l.google.com.                 87       IN    A        142.251.9.26
alt4.aspmx.l.google.com.                 87       IN    A        74.125.200.27
alt3.aspmx.l.google.com.                 31       IN    A        142.250.150.26
alt1.aspmx.l.google.com.                 88       IN    A        142.250.153.27
aspmx.l.google.com.                      243      IN    A        173.194.76.26
alt3.aspmx.l.google.com.                 30       IN    A        142.250.150.26


Trying Zone Transfers and getting Bind Versions:
_________________________________________________


Trying Zone Transfer for ilrd.co.il on ns1.dtnt.info ... 
AXFR record query failed: NOTAUTH

Trying Zone Transfer for ilrd.co.il on ns3.dtnt.info ... 
AXFR record query failed: NOTAUTH

Trying Zone Transfer for ilrd.co.il on ns2.dtnt.info ... 
AXFR record query failed: NOTAUTH


Brute forcing with /usr/share/dnsenum/dns.txt:
_______________________________________________
2) Dirb is used for finding directories of webservers/apps.
   Google is a good source for wordlists. https://tinyurl.com/yc2w4a7y.

3) ``````

```shell
sudo nmap -sn -PS22,3389 10.10.0.0/16 #custom TCP SYN scan
sudo nmap -sn -PU161 10.10.0.0/16 #custom UDP scan
```

4) Used dirb and found open http info page.
5) Scanned with nmap as in 3.
6) sudo nmap 10.10.2.46 -p 1-1024
Starting Nmap 7.94SVN ( https://nmap.org ) at 2025-01-14 17:18 IST
Nmap scan report for 10.10.2.46
Host is up (0.046s latency).
Not shown: 1005 filtered tcp ports (no-response), 17 filtered tcp ports (admin-prohibited)
PORT   STATE  SERVICE
21/tcp closed ftp
22/tcp open   ssh
MAC Address: 80:30:49:23:26:A7 (Liteon Technology)

7) crunch 13 13 -t +972-%%%-%%%%
