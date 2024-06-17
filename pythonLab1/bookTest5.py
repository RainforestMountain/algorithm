class A(object):
    def __init__(self):
        self.__private()
        self.public()

    def __private(self):
        print("__private() method in A")

    def public(self):
        print("public() method in A")


class B(A):
    def __private(self):
        print("__private() method in B")

    def public(self):
        print("public() method in B")


b = B()
print(dir(b))


class C(A):
    def __init__(self):
        self.__private()
        self.public()

    def __private(self):
        print("__private() method in C")

    def public(self):
        print("public() method in C")


c = C()
print(dir(c))
