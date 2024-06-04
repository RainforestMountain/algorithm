# # ##函数
# #
# # # def calsum(begin, end):
# # #     sum = 0
# # #     for i in range(begin, end + 1):
# # #         sum += i
# # #     return sum
# # #
# # # num = int(input())
# # # print(calsum(1,num))
# #
# # # def isOdd(num) :
# # #     if (num % 2 == 0):
# # #         return False
# # #     else:
# # #         return True
# # #
# # # num = int(input())
# # # print(isOdd(num))
# #
# #
# # # 多个返回值,_可忽略一些返回值
# #
# # # def getPoint():
# # #     x = 10
# # #     y = 20
# # #     return x, y
# # #
# # #
# # # a, b = getPoint()
# # # print(a, b)
# # #
# # # _,_ = getPoint()
# # """
# # 全局和局部变量
# # """
# # import math
# # import random
# #
# # # x = 24
# # #
# # #
# # # def isPrime(num):
# # #     global x
# # #     x = 2
# # #     for i in range(x, int(math.sqrt(num) + 1)):
# # #         if num % i == 0:
# # #             return False
# # #     print(i)
# # #     return True
# # #
# # #
# # # num = int(input())
# # # print(isPrime(num))
# # # print(x)
# #
# #
# # # def factor(num):
# # #     if num == 1:
# # #         return 1
# # #     return factor(num - 1) * num
# # #
# # # print(factor(6))
# #
# #
# # # def func(x, y ,flag = True,z = 5):
# # #     if flag:
# # #         return x
# # #     else:
# # #         return z
# # #
# # # print(func(10,5,False,7))
# #
# # # alist = [1, 2, 8, 9, "hello", True]
# # # print(alist)
# # # print(alist[0])
# # # print(alist[-1])#可以取负数下标转换为倒数,转换为倒数也超过最前面,也会抛异常
# # # alist = list([1,2,3,4])
# # # print(alist)
# # # ##print(alist[-15])
# # #
# # # _a = 5
# # # r_a = 6
# # #
# # # alist = alist[1:3]
# # # print(alist)
# # # alist = [1, 2, 3, 4, 5, 6, 7, "p"]#alist是一个可迭代对象
# # #
# # # print(alist[1: 5:  2])  # 切片操作范围1到5,步长为2
# # # print(alist[len(alist): 0: - 2])#由len(alist)到0,步长为 -2,左闭右开
# # # print(alist[len(alist) - 1: 0: - 1])#由len(alist)到0,步长为 -1
# # # for e in alist:
# # #     print(e)
# # # print(" ----------")
# # # for i in range(0, len(alist)):
# # #     print(alist[i])
# # #
# #
# #
# # # atuple = (1, 2, 4, "hello")
# # #
# # # print(atuple)
# # #
# # # print(atuple.count(1))
# # #
# # # alist = [1, 4, 5, 78, 9]
# # # alist.insert(1, 5)
# # # print(alist)
# # # alist.append("p")
# # # print(alist)
# # # alist.extend([1, 5])
# # # print(alist)
# # # alist.pop()
# # # print(alist)
# # # alist.pop(0)
# # # print(alist)
# # #
# # # print(5 in alist)
# # # print(alist.index("p"))
# # # print(alist.remove(4))
# # # print(alist)
# # # blist = [7, [1, 2]]
# # # print(blist)
# # # print(alist + blist)
# # #
# # # atuple = tuple(alist)
# # #
# # # print(atuple)
# # # print(type(atuple))
# # map = dict({1: 3, 2: 4, 1: 5})
# # print(map)
# # print(type(map))
# #
# # map = {"a": 3, "c": 5, "b": 4}
# # print(map)
# #
# # print(map["a"])
# # # print(map["d"])//没有key,访问val,抛异常
# # print(map["c"])
# #
# # map["d"] = 6  # 既可以新增也可以修改
# # map["a"] = 12
# # print(map)
# # map.pop("a")
# # for key in map.keys():
# #     print(f"{key}, {map[key]}")
# #
# # print(map.values())
# # print(map.items())
# # del map["d"]
# # print(map)
# # map.update({"e": 8})
# # print(map)
# # # alist = [1]
# # # #map = dict({alist: 5})
# # #
# # # map1 = dict()
# # # # map = dict({map1: 5})
# # #
# # # set = {1}
# # # map = dict({set:2})
# #
# # num = random.randrange(1, 8)
# # print(num)
# # print(num ** 2)
# # from math import ceil
# # a = 10
# # b = 10
# # print(a is b)  # 判断引用
# #
# # alist = [1, 2, 3]
# # blist = [1, 2, 3]
# # clist = eval("[1,2,3]")#有效python表达式是字符串类型eval可以转换
# # dlist = list(alist)#深拷贝不是浅拷贝
# # elist = alist
# # print(alist == blist)#python等号直接比较内容
# # print(alist is blist)#is比较引用
# # print(clist is alist)
# # print(dlist is alist)
# # print(elist is alist)#引用直接赋值了
# # del alist
# # # print(alist)
# #
# # alist = None
# # print(alist)
# #复数,j是虚数单位
# # num = 2 + 3j
# # a = 10
# # print(complex(a))
# # print(num)
# #
# import math
# print(dir (math))
#
#
#
#
#
# a = -10
# b = 50.3
#
# print(abs(a))
# print(math.ceil(b))
# print(math.cmp(a,b))


def test2():
    print("test2")

