#include <stdio.h>
#include <stdint.h>

int  encode(const  void*  raw_in,  void*  raw_out,  uint32_t  password,  size_t  len) 
{ 
    const  uint8_t*  in  =  (const  uint8_t*)raw_in; 
    uint8_t*  out  =  (uint8_t*)raw_out; 

    uint32_t  seed  =  password  ^  0xd1f3756au; 
    printf("%x\n", seed);
    size_t  i  =  0  ;
    for  (;  i  <  len;  ++i)  { 
        uint8_t  a  =  (  in[i]  ^  seed  )  >>  2; 
        uint8_t  b  =  (  (  ((uint32_t)in[i])  <<  11  )  ^  seed  )  >>  (11-6); 
        //uint8_t  b  =  (  in[i]  << 6    ^  seed >> 5; 
        
        a  &=  63; 
        b  &=  192; 
        a  =  63  &  (  a  ^  (b  <<  3)); 
        out[i]  =  a  |  b; 
        
        seed  =  (seed  *  144123481  ^  seed  ^  out[i]); 
    } 
} 


int  decode(const  void*  raw_in,  void*  raw_out,  uint32_t  password,  size_t  len) 
{ 
    const  uint8_t*  in  =  (const  uint8_t*)raw_in; 
    uint8_t*  out  =  (uint8_t*)raw_out; 

    uint32_t  seed  =  password  ^  0xd1f3756au; 
    size_t  i  =  0  ;
    for  (;  i  <  len;  ++i)  { 
        //  请在此处补全代码 
        uint8_t a = (in[i] << 2) ^ seed;
        a &= 0xfc;
        uint8_t b = ( (uint32_t) in[i] << (11-6) ^ seed ) >> 11;
        b &= 0x03;
        out[i] = a | b;
        seed  =  (seed  *  144123481  ^  seed  ^  in[i]); 
    } 
} 
int  main() 
{ 
    const  uint8_t  buf1[]  =  {0x72,  0x04,  0xc3,  0xd5,  0x05,  0xfa,  0x2e,  0x85,  0xa0,  0x94,  0xa4,  0x58,  0x83,  0x8d,  0xd5,  0xf6,  0x6b,  0x42,  0x9c,  0xdc,  0x8c,  0xc7,  0x26,  0x58,  0x99,  0x27,  0x0c,  0xb5,  0x14,  0x3a,  0x2b,  0xb3,  0x6a,  0x84,  0xdd,  0x07,  0xab,  0x0c,  }; 
    uint8_t  buf2[100]  =  {}; 
    const  uint32_t  password  =  0xd416e568u; 
    const  size_t  len  =  sizeof(buf1); 
    //decode(buf1,  buf2,  password,  len); 
    decode(buf1,  buf2,  password,  len); 
    printf("%s\n",  buf2); 
}
