"""
    self类似java中的this指针
    实例变量都是用self来定义的,只能在实例函数函数体中
    静态函数用装饰器@staticmethod来定义
    私有成员变量变量名前加两个下划线,私有函数函数名前加两个下划线
    初始化函数__init__()
    实例方法第一个参数必然为self,静态方法没有 self
    变量一旦定义必然初始化
    类变量和实例变量可以重名
    """


class cat:
    color = None

    def __init__(self, name, age, weight):
        self.name = name
        self.age = age
        self.__weight = weight
        self.color = "black"

    def toString(self):
        self.factor = 50
        print(self.name, cat.color, self.age, self.__weight, sep=", ", end="\n ")

    @staticmethod
    def dead():
        print(20)


print(cat.color)
c = cat("ni", 15, 29)
# print(cat.color)
# print(c.color)
# del c.color
# print(c.color)
# # del c
# # print(c)
#
# print(c.__dict__)
# print(c.__class__)
# print(c.__module__)

print(c.__bases__)
a = 40      # 创建对象  <40>
b = a       # 增加引用， <40> 的计数
c = [b]     # 增加引用.  <40> 的计数
print(c)
del a       # 减少引用 <40> 的计数
b = 100     # 减少引用 <40> 的计数
c[0] = -1   # 减少引用 <40> 的计数
print(c)
