#include<stdio.h>
#include<stdlib.h>

int *prime(int n1,int n2)
{
	int i,j,top=-1,flag=0;
	int *ans=malloc(100*sizeof(int));

for(i=n1;i<=n2;i++)
{
	flag=0;
		if(i<2)
		continue;
		else
		{
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			{
				flag=1;
				break;
			}

		}
		if(flag==0)
		{
				ans[++top]=i;
		}
	}
}
ans[top+1]='\0';
return ans;
}
int main()
{

	int *res;
	int num1,num2;
	printf("enter two integer numbers\n");
	fflush(stdout);fflush(stdin);
	scanf("%d%d",&num1,&num2);
	res=prime(num1,num2);
	for(int i=0;res[i]!='\0';i++)
	{
	     printf("%d ",res[i]);
	}
	return 0;
}
