Audit usage and installation for ubuntu on intel 64 bit.

1) Install auditd on your system:
	sudo apt install auditd

2) Start the auditd
	sudo systemctl start auditd

3) Enable audit
	sudo systemctl enable auditd

4) Change the rules file, for me I had to be root.
	sudo subl /etc/audit/rules.d/audit.rules

5) Add this line, it tells us to watch the chmod command, x means everything that is done to it and chmod_rule is the name (respectfuly to every falg).
	-w /usr/bin/chmod -p x -k chmod_rule

5) Check that the command is saved and restart auditd
	sudo auditctl -l | grep chmod_rule
	sudo service auditd restart

6) Run a chmod on a file and check ausearch for the logs.
	ausearch -k chmod_monitor
