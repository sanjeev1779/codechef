#include<iostream>
#include<math.h>
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
};



inline int fastread()
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
    int test_cases,i,n,ans;
    test_cases=fastread();
    int a[]={1,2,4,8,16,32,64,128,256,512,1024,2048};
    while(test_cases--)
    {
        n=fastread();
        ans=0;
        for(i=11;i>=0;i--)
        {
            ans=ans+ n/a[i];
            n= n%a[i];
            if(n==0)
                break;
        }
        writeInt(ans);
    }

return 0;
}
