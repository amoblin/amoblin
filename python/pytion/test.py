#! /usr/bin/env python
# -*- coding:utf-8 -*-
    
import hashlib
import binascii
import rsa

def str2hex(str):
    enc = []
    for i in range(0,len(str)-1):
        print i/2 + 1
        print str[i:i+2]
        print binascii.a2b_hex(str[i:i+2])
        enc.append(binascii.a2b_hex(str[i:i+2]))
        i += 2
    return "".join(enc)

if __name__ == "__main__":
    str = "fetion.com.cn:lenovo0"
    print str
    res = hashlib.sha1(str).hexdigest()
    print res
    ret = binascii.a2b_hex(res)

    key = {}
    key['e'] = int('010001',16)
    key['n'] = int('AC5EBCE82D14D801D1A72019B7C6A902A4C9C3CB638D9CEF88011432A300E426E99C0C9859ACCFA459F078527CB89558DF9A699D900D115ECFA72A91A09B3613865192747893438F1CF7F19A2FA8B4C54E66B4E17F88A51A8662BF534D6D5BC7D78F8AC7B6D3C8286EC0F396BE00989CF77A6EC83016B073F843064814E6B7A3',16)

    ret = '3CEB9579517B93FD3350DDDA71B619BEN5m�����G������Z�~!o,�'
    print "ret:",ret

    res = rsa.encrypt(ret,key)
    print res,"\n",len(res),"\n"
    res = binascii.b2a_hex(res)
    print res,"\n",len(res),"\n"
    res = binascii.b2a_hex(res)
    print res,"\n",len(res),"\n"
