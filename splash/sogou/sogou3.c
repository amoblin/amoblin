#include <stdio.h>
#include <stdint.h>

int  encode(const  void*  raw_in,  void*  raw_out,  uint32_t  password,  size_t  len) 
{ 
    const  uint8_t*  in  =  (const  uint8_t*)raw_in; 
    uint8_t*  out  =  (uint8_t*)raw_out; 

    uint32_t  seed  =  password  ^  0x32189851u; 
    size_t  i  =  0  ;
    for  (;  i  <  len;  ++i)  { 
        uint8_t  a  =  (  in[i]  ^  seed  )  >>  2; 
        uint8_t  b  =  (  (  ((uint32_t)in[i])  <<  20  )  ^  seed  )  >>  (20-6); 
        a  &=  63; 
        b  &=  192; 
        a  =  63  &  (  a  ^  (b  <<  3)); 
        out[i]  =  a  |  b; 
        seed  =  (((seed  <<  7)  ^  seed  ^  out[i])  +  608347); 
    } 
} 


int  decode(const  void*  raw_in,  void*  raw_out,  uint32_t  password,  size_t  len) 
{ 
    const  uint8_t*  in  =  (const  uint8_t*)raw_in; 
    uint8_t*  out  =  (uint8_t*)raw_out; 

    uint32_t  seed  =  password  ^  0x32189851u; 
    size_t  i  =  0  ;
    for  (;  i  <  len;  ++i)  { 
        //  请在此处补全代码 
        uint8_t a = (in[i] << 2) ^ seed;
        a &= 0xfc;
        uint8_t b = ( (uint32_t) in[i] << (20-6) ^ seed ) >> 20;
        b &= 0x03;
        out[i] = a | b;
        seed  =  (((seed  <<  7)  ^  seed  ^  in[i])  +  608347); 
    } 
} 
int  main() 
{ 
    const  uint8_t  buf1[]  =  {0x31,  0x32,  0x2f,  0x0c,  0x4c,  0x96,  0xf1,  0x6a,  0x8a,  0xdb,  0xc8,  0x32,  0x93,  0xcb,  0x50,  0x08,  0x8a,  0xe5,  0xfe,  0xf6,  0x5c,  0xaa,  0xc6,  0x26,  0x3f,  0xe7,  0x53,  0x48,  0x6e,  0xe7,  0x38,  0xb4,  0x9f,  0x4c,  0xfa,  0x42,  0x3c,  0xa4,  0x3d,  0x78,  0x71,  0x99,  0x52,  0x22,  0xcc,  0xcf,  0xe0,  0xcf,  0x43,  0xfa,  0x6a,  0xa7,  0xd5,  0xb7,  0x21,  0x70,  }; 
    uint8_t  buf2[100]  =  {}; 
    const  uint32_t  password  =  0x6667795eu; 
    const  size_t  len  =  sizeof(buf1); 
    decode(buf1,  buf2,  password,  len); 
    printf("%s\n",  buf2); 
} 


