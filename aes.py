from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
from Crypto.Hash import SHA256
from Crypto.Random import get_random_bytes
import base64

def encrypt_aes(plaintext, password):
    # 将密码转换为哈希密钥（AES-128使用16字节）
    key = SHA256.new(password.encode()).digest()[:16]
    iv = get_random_bytes(16)  # 生成随机初始化向量（IV）
    cipher = AES.new(key, AES.MODE_CBC, iv)
    padded_data = pad(plaintext.encode(), AES.block_size)  # 填充明文
    ciphertext = cipher.encrypt(padded_data)  # 加密
    return iv + ciphertext  # 返回IV + 密文

def decrypt_aes(ciphertext, password):
    key = SHA256.new(password.encode()).digest()[:16]
    iv = ciphertext[:16]  # 提取前16字节作为IV
    actual_ciphertext = ciphertext[16:]  # 剩余部分是密文
    cipher = AES.new(key, AES.MODE_CBC, iv)
    decrypted_data = cipher.decrypt(actual_ciphertext)  # 解密
    return unpad(decrypted_data, AES.block_size).decode()  # 去填充并解码

# 示例使用
if __name__ == "__main__":
    plaintext = "apple"
    password = "orange"

    # 加密
    encrypted_data = encrypt_aes(plaintext, password)
    print("加密后的数据 (Base64):", base64.b64encode(encrypted_data).decode())

    # 解密
    decrypted_text = decrypt_aes(encrypted_data, password)
    print("解密后的明文:", decrypted_text)