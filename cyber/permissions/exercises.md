1) I ran the next commands to create users, give them password and home directory
sudo useradd labuser1
sudo passwd labuser1
sudo adduser labuser2
sudo mkdir /home/labusers_home
sudo usermod -d /home/labusers_home labuser1
sudo usermod -d /home/labusers_home labuser2

2) It was created with 664 because of the umask which is 0002 on my machine.
	chmod 611 test
	chmod u+rw,g+x-wr,o+x-wr test
	umask 177 

4) PATH=$PATH:/home/lempo/git/cyber/permissions

5) They changed so others can't write to it. The ownership is determined by the user or group running the copy and that user's umask
	to keep the permissions sudo cp -rp /home/my_home /media/backup/my_home
	-p     same as --preserve=mode,ownership,timestamps

 --preserve[=ATTR_LIST]
          preserve the specified attributes (default: mode,ownership,timestamps),
          if possible additional attributes: context, links, xattr, all

6) 
