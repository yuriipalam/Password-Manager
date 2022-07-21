import base64
import hashlib
from sys import argv
from Crypto import Random
from Crypto.Cipher import AES


class AESCipher(object):
    def __init__(self, key, path):
        self.bs = AES.block_size
        self.key = hashlib.sha256(key.encode()).digest()
        self.path = path

    def encrypt(self, raw):
        raw = self._pad(raw)
        iv = Random.new().read(AES.block_size)
        cipher = AES.new(self.key, AES.MODE_CBC, iv)
        file_out = open(self.path, "ab")
        file_out.write(base64.b64encode(iv + cipher.encrypt(raw.encode())))
        file_out.write("\n".encode('utf-8'))
        file_out.close()

    def decrypt(self):
        array = []
        file_in = open(self.path, "rb")
        lines = file_in.readlines()
        for enc in lines:
            file_in.close()
            enc = base64.b64decode(enc)
            iv = enc[:AES.block_size]
            cipher = AES.new(self.key, AES.MODE_CBC, iv)
            array.append(self._unpad(cipher.decrypt(enc[AES.block_size:])).decode('utf-8'))
        return "\n".join(array)

    def _pad(self, s):
        return s + (self.bs - len(s) % self.bs) * chr(self.bs - len(s) % self.bs)

    @staticmethod
    def _unpad(s):
        return s[:-ord(s[len(s) - 1:])]


if argv[1] == "--help":
    print("example:\npy script.py --encrypt key test.psdb text\npy script.py --decrypt key test.psdb")

else:
    key, path = argv[2], argv[3]

    test = AESCipher(key, path)

    if argv[1] == "--encrypt":
        text = argv[4]
        test.encrypt(text)

    if argv[1] == "--decrypt":
        try:
            string = test.decrypt()
            if string == "":
                raise Exception
            else:
                print(string)
        except:
            print("wrong")
