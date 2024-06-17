class Test:
    def __init__(self, value):
        self.__value = value

    @property
    def value(self):
        return self.__value


t = Test(3)
print(t.value)
try:
    t.value = 5
except Exception as e:
    print(e)

t.v = 5
print(t.v)

del t.v
try:
    del t.value
except Exception as e:
    print(e)