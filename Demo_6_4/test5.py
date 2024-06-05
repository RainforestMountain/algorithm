def count_digits(alist):
    blist = list()
    for i in range(len(alist)):
        blist.append(len(str(alist[i])))
    return blist


alist = eval(input("输入列表"))
blist = count_digits(alist)
print(blist)
