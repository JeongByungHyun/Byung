#include <stdio.h>

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);

void main()
{
   int a,b,ans;
   char c;
   scanf("%d %c %d",&a,&c,&b);
   if(c=='+')
      ans=add(a,b);
   else if(c=='-')
      ans=sub(a,b);
   else if(c=='*')
      ans=mul(a,b);
   else
   {
      if(b==0)
      {
         printf("0으로 나눌수없음");
         return;
      }
      ans=div(a,b);
   }
   printf("%d%c%d=%d",a,c,b,ans);
}



int add(int a, int b)
{
   return a+b;
}
int sub
