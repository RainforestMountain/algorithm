import base64
import re

# IP置换
IP = [58, 50, 42, 34, 26, 18, 10, 2,
      60, 52, 44, 36, 28, 20, 12, 4,
      62, 54, 46, 38, 30, 22, 14, 6,
      64, 56, 48, 40, 32, 24, 16, 8,
      57, 49, 41, 33, 25, 17, 9, 1,
      59, 51, 43, 35, 27, 19, 11, 3,
      61, 53, 45, 37, 29, 21, 13, 5,
      63, 55, 47, 39, 31, 23, 15, 7
      ]

IP_inverse = [40, 8, 48, 16, 56, 24, 64, 32,
              39, 7, 47, 15, 55, 23, 63, 31,
              38, 6, 46, 14, 54, 22, 62, 30,
              37, 5, 45, 13, 53, 21, 61, 29,
              36, 4, 44, 12, 52, 20, 60, 28,
              35, 3, 43, 11, 51, 19, 59, 27,
              34, 2, 42, 10, 50, 18, 58, 26,
              33, 1, 41, 9, 49, 17, 57, 25
              ]

# 扩展置换E
E = [32, 1, 2, 3, 4, 5,
     4, 5, 6, 7, 8, 9,
     8, 9, 10, 11, 12, 13,
     12, 13, 14, 15, 16, 17,
     16, 17, 18, 19, 20, 21,
     20, 21, 22, 23, 24, 25,
     24, 25, 26, 27, 28, 29,
     28, 29, 30, 31, 32, 1
     ]
# S盒
S1 = [[14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7],
      [0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8],
      [4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0],
      [15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13]
      ]
S2 = [[15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10],
      [3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5],
      [0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15],
      [13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9]
      ]
S3 = [[10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8],
      [13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1],
      [13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7],
      [1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12]
      ]
S4 = [[7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15],
      [13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9],
      [10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4],
      [3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14]
      ]
S5 = [[2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9],
      [14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6],
      [4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14],
      [11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3]
      ]
S6 = [[12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11],
      [10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8],
      [9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6],
      [4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13]
      ]
S7 = [[4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1],
      [13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6],
      [1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2],
      [6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12]
      ]
S8 = [[13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7],
      [1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2],
      [7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8],
      [2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11]
      ]
S = [S1, S2, S3, S4, S5, S6, S7, S8]

# P盒
P = [16, 7, 20, 21,
     29, 12, 28, 17,
     1, 15, 23, 26,
     5, 18, 31, 10,
     2, 8, 24, 14,
     32, 27, 3, 9,
     19, 13, 30, 6,
     22, 11, 4, 25
     ]
# 密钥的产生
# 置换选择一，舍弃64位密钥的奇偶校验位
key_zhihuan1 = [57, 49, 41, 33, 25, 17, 9,
                1, 58, 50, 42, 34, 26, 18,
                10, 2, 59, 51, 43, 35, 27,
                19, 11, 3, 60, 52, 44, 36,
                63, 55, 47, 39, 31, 23, 15,
                7, 62, 54, 46, 38, 30, 22,
                14, 6, 61, 53, 45, 37, 29,
                21, 13, 5, 28, 20, 12, 4
                ]
# 置换选择二，得到48位密钥
key_zhihuan2 = [14, 17, 11, 24, 1, 5,
                3, 28, 15, 6, 21, 10,
                23, 19, 12, 4, 26, 8,
                16, 7, 27, 20, 13, 2,
                41, 52, 31, 37, 47, 55,
                30, 40, 51, 45, 33, 48,
                44, 49, 39, 56, 34, 53,
                46, 42, 50, 36, 29, 32
                ]

# 循环移位位数
rotate_left = [1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1]


# IP置换
def IP_zhihuan(plaintext):  # 第一位58，意为将原明文的第58位移动到第一位
    text = ''
    for i in IP:
        text += plaintext[i - 1]  # 从0开始,所以减一
    return text


# 扩展运算
def E_kuozhan(l1):
    text = ''
    for i in E:
        text += l1[i - 1]
    return text


# 扩展后的比特与48位密钥异或
def yihuo(afterE, round_key):
    text = ''
    for i in range(48):
        text += str(int(afterE[i]) ^ int(round_key[i]))
    return text


# S盒压缩
def S_yasuo(afterYihuo):
    text = ''
    for k in range(0, 48, 6):
        i = int(afterYihuo[k]) * 2 + int(afterYihuo[k + 5])  # 第1和第6组成行
        j = int(afterYihuo[k + 1]) * 8 + int(afterYihuo[k + 2]) * 4 + int(afterYihuo[k + 3]) * 2 + int(
            afterYihuo[k + 4])  # 第2,3,4,5算出列
        text += str('{:04b}'.format(S[k // 6][i][j]))  # '{:04b}'.format(i):十进制转4位二进制
    return text


# P盒置换
def P_zhihuan(afterS):
    text = ''
    for i in range(32):
        text += str(afterS[P[i] - 1])
    return text


# 轮函数F
def F(l1, key):
    l1 = E_kuozhan(l1)  # 将32位扩展到48位
    afterYihuo = yihuo(l1, key)  # 与轮密钥异或
    afterS = S_yasuo(afterYihuo)  # S盒压缩
    text = P_zhihuan(afterS)  # P盒置换
    return text


# 轮密钥生成
def makeRoundKey(key):
    text = ''
    roundKey = []
    # 第一次压缩置换，将64位密钥压缩成56位
    for i in key_zhihuan1:
        text += key[i - 1]
    # 分成左右两个部分
    C0 = text[:28]
    D0 = text[28:]
    # 按照循环移位表(16项)进行移位
    for i in range(16):
        C0 = C0[rotate_left[i]:] + C0[:rotate_left[i]]
        D0 = D0[rotate_left[i]:] + D0[:rotate_left[i]]
        temp = C0 + D0
        result = ''
        # 进行第二次压缩置换，将56位压缩到48位
        for i in key_zhihuan2:
            result += temp[i - 1]
        roundKey.append(result)
    return roundKey


# IP逆置换
def ipInverse(afterF):
    ciphertext = ''
    for i in IP_inverse:
        ciphertext += afterF[i - 1]
    return ciphertext


# 字符串转二进制
def str2bit(text):
    result = ''
    for i in text:
        a = bin(ord(i))[2:]  # 转换成二进制后前面会有0b字符,所以从2开始
        for j in range(0, 8 - len(a)):  # 补齐八位
            a = '0' + a
        result += a
    return result


# 二进制转字符串
def bit2str(text):
    result = ''
    a = re.findall(r'.{8}', text)  # re.findall:函数返回包含所有匹配项的列表,每8位一个字符
    for i in a:
        result += chr(int(i, 2))  # 2进制转10进制再转成字符
    return result


def encrypt(plaintext, key):
    # IP置换
    text = IP_zhihuan(plaintext)
    roundKey = makeRoundKey(key)  # 生成轮密钥
    # 分成左右32位
    L0 = text[:32]
    R0 = text[32:]
    # 16轮加密
    for i in range(16):
        temp = R0
        result = F(R0, roundKey[i])
        R0 = ''
        for j in range(32):
            R0 += str(int(L0[j]) ^ int(result[j]))
        L0 = temp
    zuizhong = R0 + L0  # 最后要左右交换
    ciphertext = ipInverse(zuizhong)
    return ciphertext


def decrypt(ciphertext, key):
    # IP置换
    text = IP_zhihuan(ciphertext)
    roundKey = makeRoundKey(key)  # 生成轮密钥
    Li = text[:32]
    Ri = text[32:]
    # 解密时轮密钥需要倒着使用
    for i in range(15, -1, -1):
        temp = Ri
        result = F(Ri, roundKey[i])
        Ri = ''
        for j in range(32):
            Ri += str(int(Li[j]) ^ int(result[j]))
        Li = temp
    zuizhong = Ri + Li
    plaintext = ipInverse(zuizhong)
    return plaintext


# 检查text是否是64位
def check_text_64(text):
    lenth = len(text)
    if lenth % 64 != 0:
        for i in range(64 - (lenth % 64)):
            text += '0'
    return text


# 检查密钥是否为64位
def check_key_64(key):
    lenth = len(key)
    if lenth < 64:
        for i in range(64 - (lenth % 64)):
            key += '0'
    else:
        key = key[0:64]  # 超过64位截取64位
    return key


def des_en(text, key):
    text = check_text_64(str2bit(text))
    result = ''
    key2 = check_key_64(str2bit(key))
    temp = re.findall(r'.{64}', text)
    for i in temp:
        result += encrypt(i, key2)
    return result


def des_de(text, key):
    text = check_text_64(str2bit(text))
    result = ''
    key2 = check_key_64(str2bit(key))
    temp = re.findall(r'.{64}', text)
    for i in temp:
        result += decrypt(i, key2)
    return result


if __name__ == '__main__':
    while True:
        choice = int(input("请输入你的选择：1.加密  2.解密   0.退出   "))
        if choice == 1:
            plaintext = input("请输入明文：").replace(' ', '')
            key = input("请输入密钥：").replace(' ', '')
            ciphertext = des_en(plaintext, key)
            out = bit2str(ciphertext)
            print("密文为：" + out)
            out1 = base64.b64encode(out.encode("utf-8")).decode("utf-8")
            print("base64加密后的密文为：" + out1 + '\n')
        elif choice == 2:
            ciphertext = input("请输入base64编码的密文：").replace(' ', '')
            ciphertext = base64.b64decode(ciphertext.encode("utf-8")).decode("utf-8")
            key = input("请输入密钥：").replace(' ', '')
            plaintext = des_de(ciphertext, key)
            out = bit2str(plaintext)
            print("明文为：" + out + '\n')
        else:
            break
