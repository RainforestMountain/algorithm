# 写入二进制文件
import struct

with open('a.bat', 'wb') as f:
    integer_value = 10
    float_value = 3.14
    bool_value = True
    english_string = 'Hello, world!'
    chinese_string = '你好，世界！'

    f.write(integer_value.to_bytes(4, 'little'))  # 整数占4个字节
    f.write(bytearray(struct.pack("f", float_value)))  # 浮点数占4个字节
    f.write(bool_value.to_bytes(1, 'little'))  # 布尔值占1个字节
    f.write(english_string.encode('utf-8'))  # 英文字符串
    f.write(chinese_string.encode('utf-8'))  # 中文字符串

# 写入文本文件
with open('a.txt', 'w', encoding='utf-8') as f:
    f.write(f"{integer_value}\n{float_value}\n{bool_value}\n{english_string}\n{chinese_string}")

# 比较文件长度
import os

bat_file_size = os.path.getsize('a.bat')
txt_file_size = os.path.getsize('a.txt')

if bat_file_size == txt_file_size:
    print("二进制文件和文本文件的长度相同")
else:
    print("二进制文件和文本文件的长度不同")
