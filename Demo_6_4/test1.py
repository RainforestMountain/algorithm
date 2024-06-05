import math


def isPrime(n):
    for i in range(2, int(math.sqrt(n) + 1)):
        if n % 2 == 0:
            return False
    return True


n = int(input())

print(isPrime(n))
