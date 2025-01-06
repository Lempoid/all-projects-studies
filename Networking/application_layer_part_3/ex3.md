DNS Zone Transfer Exercise

Objective
Set up a DNS server with a master-slave configuration, verify zone transfers, and troubleshoot issues during the process.

Steps

1. Install BIND9

Install BIND9 on both master and slave servers


2. Configure the Master Server


Edit /etc/bind/named.conf.local on the master:


In named.conf.local write the next lines to give a zone a name and from where to take configuration of said zone:

zone "studentName" {
    type master;
    file "/etc/bind/db.studentName";
};


Create the zone file, copy db.local to db.StudentName and change it as needed:


Populate the zone file:
$TTL    86400
@       IN      SOA     studentName. admin.studentName.prevStudentNameChain. (
                    2024010102 ; Serial
                    3600       ; Refresh
                    1800       ; Retry
                    1209600    ; Expire
                    86400 )    ; Minimum TTL
; Name Server
@       IN      NS      studentName.prevStudentNameChain.
@		IN 		A 		student IP address
@       IN      NS      ns1.studentName.
ns1     IN      A       192.168.1.166
admin   IN      A       192.168.1.167
backup  IN      A       192.168.1.168



3. Check the configuration:
sudo named-checkconf /etc/bind/named.conf
sudo named-checkzone chananya.templeman /etc/bind/db.chananya.templeman


Restart bind9 and named with systemctl:


4. Verify Zone Transfer

Use dig to query the slave server:
dig @nextStudentIPaddress nextStudentName