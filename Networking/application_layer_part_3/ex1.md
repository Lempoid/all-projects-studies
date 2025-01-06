1) Downloaded MTU and made a vm using kali image.

2) Make sure openssh-server is installed

3) Make sure that the ssh server works on the vm (systemctl status ssh)

3) Try to connect: ssh user@ip

4) Now make public and private keys. Send the public key to the server with ssh-copy-id -i path_to_pub_key user@remote_server (ssh-copy-id -i ~/.ssh/id_rsa.pub user@remote_server)

5) To forbid password, connect to server and open with nano or vim /etc/ssh/sshd_config. Change the line "#PasswordAuthentication yes" to "PasswordAuthentication no"

6) Get file from server: scp -r -i path_to_private_key user@ip:path_to_file_on_server path_to_local_save_location