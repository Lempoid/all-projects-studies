"""
everything in one file except for exercise 2

Author: Alex Breger
Review: Ben Bortkovsky 12.11.2024

"""

import os
import stat
import sys
import areas

num = 1


def ex1(var):
    if var in globals():
        return True
    else:
        return False

def ex3():
    print(f"User name: \
    {os.getlogin()} \n OS name: \
    {os.name}\n CWD: {os.getcwd()}")

def ex4():
    print(sys.argv[::-1])


def ex5():
    file_name = sys.argv[1]
    for root, dirs, files in os.walk('/'):
        for file in files:
            print(file)
            if file == file_name:
                perms = stat.S_IXUSR | stat.S_IXGRP
                os.chmod(file, perms | os.stat(file).st_mode)




print(ex1('num'))
print(areas.circle_area(5),
      areas.triangle_area(2, 5),
      areas.rectangle_area(2, 5))
ex3()
ex4()
ex5()