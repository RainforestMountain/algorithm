import math


class Shape(object):
    def __init__(self, name):
        self.name = name

    def Area(self):
        pass

    def Perimeter(self):
        pass


class Circle(Shape):
    def __init__(self, name, radius):
        super().__init__(name)
        self.radius = radius

    def Area(self):
        return math.pi * self.radius * self.radius

    def Perimeter(self):
        return 2 * math.pi * self.radius


class Rectangle(Shape):
    def __init__(self, name, length, width):
        super().__init__(name)
        self.length = length
        self.width = width

    def Area(self):
        return self.length * self.width

    def Perimeter(self):
        return 2 * (self.length + self.width)


class Square(Shape):
    def __init__(self, name, edge):
        super().__init__(name)
        self.edge = edge

    def Area(self):
        return self.edge * self.edge

    def Perimeter(self):
        return self.edge * 4


shape = None
c1 = Circle("circle", 5)
r1 = Rectangle("rectangle", 5, 4)
s1 = Square("square", 4)
# 圆
shape = c1
print(shape.name, ":")
print(f"area = {shape.Area()}")
print(f"Perimeter = {shape.Perimeter()}")
# 矩形
shape = r1
print(shape.name, ":")
print(f"area = {shape.Area()}")
print(f"Perimeter = {shape.Perimeter()}")
# 正方形
shape = s1
print(shape.name, ":")
print(f"area = {shape.Area()}")
print(f"Perimeter = {shape.Perimeter()}")
