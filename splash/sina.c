#include <stdio.h>
#include <string.h>
void foo_0(void)

{

   unsigned int a = 6;

   int b = -20;

   (a+b>6)?puts(">6"):puts("<=6");//puts为打印函数

}

void foo_1(void)

{

   char string[10],str1[10];

   int i;

   for(i=0;i<10;i++)

   {

     str1[i] = 'a';

   }

   strcpy(string, str1);

   puts(string); //puts为打印函数

}

void foo_2(void)

{

double d = 100.25;

int x = d;

int *pInt = (int*)&d;

puts(x); //puts为打印函数

puts(*pInt);

}

//写出下列的输出

int main()

{

   foo_0();

   foo_1();

   foo_2();

   return 1;

}

