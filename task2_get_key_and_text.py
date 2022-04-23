import binascii
from Crypto.Cipher import AES

with open('possible_key.txt') as fp:
    keys=fp.readlines()

for keyhex in keys:
    keyhex=keyhex.rstrip()

    iv=binascii.unhexlify('09080706050403020100A2B2C2D2E2F2'.lower())
    key=binascii.unhexlify(keyhex.lower())
    plaintext=binascii.unhexlify('255044462d312e350a25d0d4c5d80a34'.lower())

    encryptor=AES.new(key, AES.MODE_CBC, iv)
    ciphertext=encryptor.encrypt(plaintext)

    if(ciphertext==binascii.unhexlify('d06bf9d0dab8e8ef880660d2af65aa82'.lower())):
        iv=  binascii.hexlify(iv)
        plaintext = binascii.hexlify(plaintext)
        key = binascii.hexlify(key)
        ciphertext = binascii.hexlify(ciphertext)
        print ("\n the IV is: " + iv + "  ,and the plaintext is: " + plaintext + " \n\nand the key is: " + key + "  ,and the ciper text is: " + ciphertext)

