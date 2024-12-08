Opening a basic apache2 server on ubuntu:


1) install apache2

sudo apt install apache2

2) install php with apachelib
sudo apt install php libapache2-mod-php

3) make info.php file in /var/www/html/ just to show information and for testing.
write in it 
<?php
	info()
?>

4) make hello.php file in same dir 
write int it
<?php
	echo "HelloWorld!"
?>

5) run apache2 
sudo service apache2 start

6) navigate to localhost/hello.php in the browser