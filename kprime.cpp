#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#define LL long long
using namespace std;

#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked

inline void writeInt(int x)
{
     if(x==-1)
     {
              PUTCHAR('-');
              PUTCHAR('1');
              PUTCHAR('\n');
     }
     else
     {
       int i = 10;
       char buf[11];
      // buf[10] = 0;
      buf[10] = '\n';

     do
     {
        buf[--i] = x % 10 + '0';
        x/= 10;
     }while(x);
     do
     {
        PUTCHAR(buf[i]);
     } while (buf[i++] != '\n');
     }
}

inline int fastRead_int()
{
        int noRead=0;
        char p=getchar_unlocked();
        for(; p<33;) {
                p=getchar_unlocked();
        };
        while(p>32) {
                noRead = (noRead << 3) + (noRead << 1) + (p - '0');
                p=getchar_unlocked();
        }
        return noRead;
};


main()
{
    int test_cases,i,j,k,ans,A,B,K,c;
    int a[100002];
    test_cases=fastRead_int();
    int ran;
    while(test_cases--)
    {
        A= fastRead_int();
        B=fastRead_int();
        K=fastRead_int();
        ans=0;
        for(i=A;i<=B;i++)
        {
            c=0;
           int i_new = i;
           ran=0;
            memset(a,0,sizeof(a));
            for(j=2;j*j<=i_new;j++)
            {
                while(i_new%j==0)
                {
                   // a[j]++;
                   if(a[j]==0)
                   {
                       a[j]=1;
                        c++;
                   }
                    i_new=i_new/j;
                }
                if(c>K)
                    break;
            }
            if(i_new!=1){
                    {
                    if(a[i_new]==0)
                        c++;
                    }
            }

            if(c==K)
                ans++;

        }
        writeInt(ans);
    }
return 0;
}
