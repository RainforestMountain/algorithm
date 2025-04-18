import random
import string
from _random import Random
from binascii import b2a_hex

import AES


def encrypt_AES_ECB(str, key):
    str = align(str)
    key = align(key, True)
    iv = Random.new().read(AES.block_size)
    AESCipher = AES.new(key, AES.MODE_ECB, iv)
    cipher = AESCipher.encrypt(str)
    return b2a_hex(cipher)


def align(str, isKey=False, isAES=True):
    if isKey:
        if isAES:
            if len(str) > 16:
                return str[0: 16]
            else:
                return align(str)
        else:
            if len(str) > 8:
                return str[0:8]
            else:
                return align(str)
    else:
        zerocount = 16 - len(str) % 16
        for i in range(0, zerocount):
            str = str + '\0'
        return str


def keyGenerater(length):
    if length not in (16, 24, 32):
        return None
    x = string.ascii_letters + string.digits
    return ''.join([random.choice(x) for i in range(length)])
