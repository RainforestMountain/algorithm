
import cmath
import filecmp
import random


# a = -10
# b = 15.3
# print(abs(a))
# # print(cmp(a,b))
# print(bin(a))
# print(filecmp.cmp(a, b))

# python乘法可以作为复制
# src = "abcd"
# alist = [1, 2, 3, 4]
# # print(src * 4)
# # print(alist * 2)
#
# print(src[0])
# print(src[-1])
# print(ord(src[0]))
# print(src[1:3:1])

# s1 = "hello"
# s2 = "python"
#
# print(s1 + s2)
# print(s1 * 3)
# print(s1[-1])
# print(s1[0: 5: 2])
# print('H' in s1)
# print('H' not in s1)
# print(r'\r')  # r或者R表示不让转义

# 格式化字符串3中
# f-string
# print(f"hello , {1 + 2}")
# # %和占位符来格式化
# print("hello, % d" % (1 + 2))
# print("hello, %.5f" % (1 + 2))
# #用format()方法,将{}中的数字依次替换成传入的参数,数字必须要在范围内
# print("{0} ,{2}".format("hello", (2 + (7 + 5j))))

#
# alist = [1, 2, 5, 6, 7, 8.9,2.3, "hello"]
#
# print(len(alist))
# # print(max(alist))#max获取的最大值序列要可以比
# del alist[-1]
# print(max(alist))
# print(min(alist))
# print(list({5: 7, 8: 7, 9: 8, 5: 3}))  # 将序列对象转换为list,序列对象包括字符串, 列表, 集合, 元组,字典, 字典是键值转换为列表
# print(sum((5, 7, 8)))
# print(str(alist))#字符串包括那个方括号
# print(sorted(alist))

# alist = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 9]
# atuple = (1, 3, 9, 4, 2)
# map = {4: 3, 2: 8, 9: 7}
# aset = {7, 5, 6, 6, 3}
# # print(atuple)
# # print(map)
# # print(aset)
#
# print(alist[0])
# print(alist[-1])
# print(alist[1:6:2])
# print(alist.count(9))
# print(len(alist))

# alist = [1, 2, 3, 4, 5]
# for i in range(0, len(alist)):
#     val = alist.pop(0)
#     alist.append(val)
#     print(alist)


# month = int(input("输入月份 : "))
# if month >= 3 and month <= 5:
#     print("春季")
# elif month >= 6 and month <= 8:
#     print("夏季")
# elif month >= 9 and month <= 11:
#     print("秋季")
# elif month == 12 or (month >= 1 and month <= 2):
#     print("冬季")
# else:
#     print("输入错误")
#
# void = 5
# alist = [1, 2, 6, 7]
# print(dir(random))
#
# num = random.choice(alist)
# print(num)

# count = 1
# num = 0
#
#
# def test():
#     global count
#     for i in range(3):
#         count += 1
#     num = 8
# test()
# print(count, num)

# def fun(*p):
#     avg = sum(p) / len(p)
#     g = [i for i in p if i > avg]
#     return (avg,) + tuple(g)
#
#
# print(fun(1, 2, 3, 4))

# x = 2
#
#
# def fun1():
#     print(x, end=" ")
#
#
# def fun2():
#     global x
#     x = x + 1
#     print(x, end=" ")
#
#
# fun1()
# fun2()
#
# print(x, end=" ")
# print()
# for i in range(1, 5):
#     print(i,i + 1, sep=",", end=" ")


# 集合
# cset = {} #这样不会创建空集合,只会当做字符串
# aset = {1}
# bset = set({1, 2})
#
# print(aset)
# print(bset)
# print(cset)


# alist = [1, 3, 8, 9, 12]
# blist = [i for i in alist if i > 3]
# print(blist)

def getsum(a, b):
    return a + b


def getlistsum(*p):
    sum = 0
    for i in range(len(p)):
        sum += p[i]
    return sum


def wait():
    pass


x = 5
y = 6
my_sub = lambda x, y: x - y
print(my_sub(5, 6))
