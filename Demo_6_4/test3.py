# 递归

def binary(p, left, right, target):
    if left > right:
        return -1
    mid = left + ((right - left) >> 1)
    if p[mid] == target:
        return mid
    elif p[mid] < target:
        return binary(p, mid + 1, right, target)
    else:
        return binary(p, left, mid - 1, target)


alist = eval(input("输入list"))
alist = sorted(alist)
print(alist)
print(binary(alist, 0, len(alist) - 1, 2))
