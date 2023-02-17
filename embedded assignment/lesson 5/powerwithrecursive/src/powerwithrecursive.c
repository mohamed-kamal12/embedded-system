#include<stdio.h>

int power(int num,int p)
{
   if(p==0)
   {
   return 1;
   }
   else
   {
     return num*power(num,p-1);
   }
}
int main(void)
{
	int n,res,pow;
	printf("enter the base number\n");
	fflush(stdout);fflush(stdin);
	scanf("%d",&n);
	printf("enter the power number\n");
    fflush(stdout);fflush(stdin);
	scanf("%d",&pow);
	res=power(n,pow);
	printf("the result= %d\n",res);
	return 0;
}
