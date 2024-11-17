"""
Simple Point class
Author: Alex Breger
Reviwed by: Ben Bortkevich

"""

from math import sqrt

class Point:
    def __init__(self, x = 0, y = 0):
        self._x = x
        self._y = y

    @property
    def x(self):
        return self._x

    @x.setter
    def x(self, new_value):
        self._x = new_value

    @x.deleter
    def x(self):
        del self._x

    @property
    def y(self):
        return self._y

    @y.setter
    def y(self, new_value):
        self._y = new_value

    @y.deleter
    def y(self):
        del self._y

    def distance_from_origin(self, origin_x, origin_y):
        return sqrt((origin_x - self.x) ** 2 + (origin_y - self.y) ** 2)




point = Point(5,5)
print(point.x,point.y)
print(point.distance_from_origin(5,5))