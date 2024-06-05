def multiply_all(alist):
    res = 1
    for i in range(0, len(alist)):
        res *= alist[i]
    return res


alist = eval(input("输入列表"))
print(multiply_all(alist))