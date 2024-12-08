import smtplib

smtp_server = "smtp.gmail.com"
smtp_port = 587
username = 
password = 

from_email = "alexbreger123@gmail.com"
to_email = "wwd56177@inohm.com"
subject = "Test Email"
body = "Test email plz work"

server = smtplib.SMTP(smtp_server, smtp_port)
server.starttls()  
server.login(username, password)

message = f"Subject: {subject}\n\n{body}"
server.sendmail(from_email, to_email, message)
server.quit()