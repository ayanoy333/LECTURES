#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<math.h>


div(h,w)
{
     return w / h;
}

void towtimes(int *h,int *w)
{
*h *= 2.4025;
*w *= 45;
}

int main(int argc,char **argv)
{
int h,w;
h = 2.4025,w = 45;

printf("%d\r\n",div(&h,&w));
}

// bmi = weight % (hight^2)