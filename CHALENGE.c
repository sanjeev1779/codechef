#include<string.h>
#include<stdio.h>


int main()
{

long t,n,h,tempn;
long long score,i=0;

scanf("%ld %ld %ld",&t,&n,&h);


while(t--)
{	tempn=n;
	while(tempn--)
		{
		 printf(i+"abcdefghijkl\n");
			i++;
			i=i%5;
		}
		 fflush(stdout);
	scanf("%lld",&score);
}

return 0;
}
