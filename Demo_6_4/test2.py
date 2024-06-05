def factor(n):
    if n == 1:
        return {1}
    res = list()
    for i in range(2, n // 2):
        if n == 1:
            break
        if n % i == 0:
            while n % i == 0:
                res.append(i)
                n = n // i
    return res


num = int(input())
print(factor(num))
