# a = 5
# print(a)
# print(type(a))
#
# b = 0.2
# print(b)
# print(type(b))
#
# c = 0.3
# d = 0.5
# print((b + c) == d)
#
# src = "hello world"
# print(src)
# print(type(src))
#
# dest = "hello python"
#
# print(src + dest)
# print(len(src) + len(dest))
"""
代码演示
"""
# flag = False  # 需要大写
# print(flag)
# flag = True
# print(flag)
# print(type(flag))
#
# flag = "nihao"
# print(flag)
# print(type(flag))
#
# print("hello")
# a = 50;
# print(f"a = {a}, flag = {flag}")
# print("a = ", a, "flag = ", flag)

# a = int(input("输入一个整数"))
# b = int(input("输入一个整数"))
#
# print(a, " ", b)
#
# # print(f"a + b = { a + b }")#用{}内嵌需要用f - string带有f前缀的字符串
# # a = str(a)
# # b = str(b)
# # print(f" a + b = {a + b}")
#
# print(a + b)
# print(a - b)
# print(a ** b)
# print("%.2f" % (a / b))
# print(a // b)
# print(a % b)

# a = 10
# b = 20
# print(a < b)
# print(a <= b)
# print(a > b)
# print(a >= b)
# print(a == b)
# print(a != b)
# a = 'hello python'
# b = 'hello python'
# print(a < b)
# print(a <= b)
# print(a > b)
# print(a >= b)
# print(a == b)
# print(a != b)
#
# print(0.1 + 0.2 == 0.3)#用常量不可以,用变量可以相等比较
# print(0.1 + 0.2)
# a = 0.1
# b = 0.2
# print(a + b)


# a = 10
# b = 20
# c = 30
# #and or 都有短路特性
# print(a < b and a > c)
# print(a < b or a > c)
# print(not a < c )
# print(a < b < c)#a < b and b < c的结合

# a = 5
# b = 10
# a, b = b, a
# # a++,没有++,--
# print(a)
# print(b)
#
# a += 1
# print(a)
#
# choice = int(input())
#
# if choice == 1:
#     print("1")
# elif choice == 2:
#     print("2")
# else:
#     print("other")

# num = int(input("输入一个整数"))
# if num % 2 == 0:
#     print("偶数")
# else :
#     print("奇数")

# year = int(input("输入年份"))
# if ((year % 4 == 0) and (year % 100 != 0)) or (year % 400 == 0):
#     print("闰年")
# else:
#     print("不是闰年")


# num = int(input("输入整数"))
#
# if num == 1:
#     pass
# else:
#     print("yes")

# num = 1
# sum = 0;
# while num <= 10 :
#     sum += num
#     num += 1
# print(sum)

# num = int(input("输入整数"))
# ret = 1
# i = 1
# while i <= num:
#     ret *= i
#     i += 1
# print(ret)


num = 5
i = 1
sum = 0
# while i <= num :
#     ret = 1
#     j = 1
#     while (j <= i) :
#         ret *= j
#         j += 1
#     sum += ret
#     i += 1
# print(sum)

# for i in range(1, 6, 1):
#     ret = 1
#     for j in range(1, i + 1, 1):
#         ret *= j
#     sum += ret
# print(sum)
# i = 3
# count = 0
# for i in range(1, 6):
#     if i == 3:
#         continue
#     if i == 5:
#         break
#     count += 1
# print(count)

def test1():
    print("bag")