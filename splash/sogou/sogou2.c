#include <stdio.h>
#include <stdint.h>

int  encode(const  void*  raw_in,  void*  raw_out,  uint32_t  password,  size_t  len) 
{ 
    const  uint8_t*  in  =  (const  uint8_t*)raw_in; 
    uint8_t*  out  =  (uint8_t*)raw_out; 

    uint32_t  seed  =  password  ^  0xbc49cb0au; 
    size_t  i  =  0  ;
    for  (;  i  <  len;  ++i)  { 
        uint8_t  a  =  (  in[i]  ^  seed  )  >>  5; 
        uint8_t  b  =  (  (  ((uint32_t)in[i])  <<  17  )  ^  seed  )  >>  (17-3); 
        a  &=  7; 
        b  &=  248; 
        a  =  7  &  (  a  ^  (b  <<  3)); 
        out[i]  =  a  |  b; 
        seed  =  ((seed  ^  in[i])  *  1792013  +  in[i]); 
    } 
} 


int  decode(const  void*  raw_in,  void*  raw_out,  uint32_t  password,  size_t  len) 
{ 
    const  uint8_t*  in  =  (const  uint8_t*)raw_in; 
    uint8_t*  out  =  (uint8_t*)raw_out; 

    uint32_t  seed  =  password  ^  0xbc49cb0au; 
    size_t  i  =  0  ;
    for  (;  i  <  len;  ++i)  { 
        //  请在此处补全代码 
        uint8_t a = in[i] << 5;
        uint8_t b = in[i] >> 3;
        a = (~a) & 0xf8;
        out[i] = a | b;
    } 
} 
int  main() 
{ 
    const  uint8_t  buf1[]  =  {0x21,  0x81,  0x39,  0x60,  0xd4,  0x4a,  0x2f,  0xb1,  0xe7,  0x9d,  0x3e,  0xb6,  0xba,  0x56,  0x5a,  0x56,  0x7a,  0x67,  0x2e,  0xa9,  0xb9,  0x33,  0x9c,  0x12,  0x84,  0x57,  0x41,  0xd1,  0x6a,  0x81,  0x09,  0x22,  0x6d,  0x57,  0xfc,  0x02,  0x4c,  0x20,  0x33,  0xdf,  0xbf,  0x41,  }; 
    uint8_t  buf2[100]  =  {}; 
    const  uint32_t  password  =  0xeb163ffcu; 
    const  size_t  len  =  sizeof(buf1); 
    decode(buf1,  buf2,  password,  len); 
    printf("%s\n",  buf2); 
} 


