class Root:
    __total = 0

    def __init__(self, v):
        self.__value = v
        Root.__total += 1

    def show(self):
        print("self.__value:", self.__value)
        print("Root.__total:", self.__total)

    @classmethod
    def classShowTotal(cls):
        print(cls.__total)

    @staticmethod
    def staticShowTotal():
        print(Root.__total)


r = Root(3)

r.classShowTotal()
r.staticShowTotal()
r.show()

rr = Root(5)
Root.classShowTotal()
Root.staticShowTotal()
try:
    Root.show()
except Exception as e:
    print(e)

Root.show(r)
r.show()
Root.show(rr)
rr.show()
