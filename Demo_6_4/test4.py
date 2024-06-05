def Encrypt_string(src, k):
    res = str()
    for char in src:
        if char.isalpha():
            shift = 3 if char.islower() else 3
            shift_char = shifted_char = chr(
                ((ord(char) - ord('a' if char.islower() else 'A') + k) % 26) + ord('a' if char.islower() else 'A'))
            res += shift_char
        else:
            res += shift_char
    return res


src = input("输入字符串")
k = int(input("输入k"))
src = Encrypt_string(src, k)
print(src)
