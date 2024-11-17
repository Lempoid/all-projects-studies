"""
Exception worksheet. Trying to do an exception with division by 0.
Author: Alex Breger
Reviwed by: Ben Bortkevich
"""

import re
def ex5(password):
    try:
       if (8 >= len(password) and re.search("[a-z]", password)
            and re.search("[A-Z]", password) and re.search("[0-9]", password)
            and re.search("[@#%&]", password)):
           1/0
           return 1
    except Exception as e:
        print(f"exception: {e}")

    return 0

print(ex5("Pass1@rd"))