#include<stdio.h>
#include<stddef.h>
int fastread()
{
        int input;
        char c=0;
        while (c<33) c=getchar_unlocked();
        input=0;
        while (c>33)
        {
        input=input*10+c-'0';
        c=getchar_unlocked();
        }
        return input;
}

int main()
{
int n,t,i,j;
int a[102][102];
n=fastread();
while(n--)
{
t=fastread();

 for(i=0;i<t;i++)
 	{for(j=0;j<=i;j++)
   {
   a[i][j]=fastread();
   }
   }

for(i=t-2;i>=0;i--)
{for(j=0;j<=i;j++)
{a[i][j]+=((a[i+1][j]>a[i+1][j+1])?a[i+1][j]:a[i+1][j+1]);
}
}
printf("%d\n",a[0][0]);
}

return 0;
}
