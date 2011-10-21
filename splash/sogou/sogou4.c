#include <stdio.h>
#include <stdint.h>

int  encode(const  void*  raw_in,  void*  raw_out,  uint32_t  password,  size_t  len) 
{ 
    const  uint8_t*  in  =  (const  uint8_t*)raw_in; 
    uint8_t*  out  =  (uint8_t*)raw_out; 

    uint32_t  seed  =  password  ^  0x3bee5fa6u; 
    size_t  i  =  0  ;
    for  (;  i  <  len;  ++i)  { 
        uint8_t  a  =  (  in[i]  ^  seed  )  >>  1; 
        uint8_t  b  =  (  (  ((uint32_t)in[i])  <<  20  )  ^  seed  )  >>  (20-7); 
        a  &=  127; 
        b  &=  128; 
        a  =  127  &  (  a  ^  (b  <<  3)); 
        out[i]  =  a  |  b; 
        seed  =  (seed  *  144123481  ^  seed  ^  out[i]); 
    } 
} 


int  decode(const  void*  raw_in,  void*  raw_out,  uint32_t  password,  size_t  len) 
{ 
    const  uint8_t*  in  =  (const  uint8_t*)raw_in; 
    uint8_t*  out  =  (uint8_t*)raw_out; 

    uint32_t  seed  =  password  ^  0x3bee5fa6u; 
    size_t  i  =  0  ;
    for  (;  i  <  len;  ++i)  { 
        //  请在此处补全代码 
        uint8_t a = (in[i] << 1) ^ seed;
        a &= 0xfe;
        uint8_t b = ( (uint32_t) in[i] << (20-7) ^ seed ) >> 20;
        b &= 0x01;
        out[i] = a | b;
        seed  =  (seed  *  144123481  ^  seed  ^  in[i]); 
    } 
} 
int  main() 
{ 
    const  uint8_t  buf1[]  =  {0x68,  0x60,  0xac,  0x8d,  0x93,  0x65,  0xeb,  0x0a,  0x64,  0x89,  0x10,  0xa9,  0x57,  0x26,  0x1a,  0x3e,  0x1b,  0x9e,  0x88,  0xa4,  0x95,  0xf8,  0xb6,  0xa7,  0xc2,  0x0c,  0xbb,  0x47,  0x3e,  0xad,  0xbe,  0x04,  0x20,  0xf7,  0xa1,  0x9a,  0xc1,  0x50,  0x4c,  0xaf,  0x2a,  0x53,  0x63,  0x50,  0x6c,  0xb3,  0x92,  0x64,  0xc4,  0x91,  0xeb,  0x38,  0x08,  0x95,  0xfa,  }; 
    uint8_t  buf2[100]  =  {}; 
    const  uint32_t  password  =  0xa21020bdu; 
    const  size_t  len  =  sizeof(buf1); 
    decode(buf1,  buf2,  password,  len); 
    printf("%s\n",  buf2); 
} 


