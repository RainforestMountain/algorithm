import  hashlib,base64

class rc4:
    def __init__(self, public_key=None):
        self.public_key = public_key or 'none_public_key'

    def encode(self, string):
        """
        加密
        :param string: 输入utf-8
        :return:
        """
        bData = [ord(i) for i in string]
        result = self.__docrypt(bData)
        result = base64.b64encode(result.encode())#编码成可见的字符
        return str(result,encoding='utf-8')

    def decode(self, string):
        """
        解密
        :param string:输入utf-8
        :return:
        """
        message = base64.b64decode(string).decode()
        bData = [ord(i) for i in message]
        deresult = self.__docrypt(bData)
        return deresult

    def __rc4_init(self, K):
        """
        :param K: 密钥
        :return:
        """
        j = 0
        K = hashlib.md5(K.encode("utf8")).hexdigest()
        k = []  # 临时数组
        SBox = []  # S盒
        for i in range(256):
            SBox.append(i)
            k.append(K[i % len(K)])  # T[i] = K[ i mod keylen ];
        for i in range(256):
            j = (j + SBox[i] + ord(k[i])) % 256
            SBox[i], SBox[j] = SBox[j], SBox[i]  # 交换S[i],S[j]
        return SBox

    def __docrypt(self,string):
        i = j = 0
        result = ''
        SBox = self.__rc4_init(self.public_key)
        for _str in string:
            i = (i + 1) % 256
            j = (j + SBox[i]) % 256
            SBox[i], SBox[j] = SBox[j], SBox[i]
            k = chr(_str ^ SBox[(SBox[i] + SBox[j]) % 256])
            result += k
        return result

_rc4 = rc4('testkey')
tempcode = _rc4.encode('学号+HelloWorldNick')
print("加密结果",tempcode)
tempdecode = _rc4.decode(tempcode)
print("解密结果",tempdecode)
