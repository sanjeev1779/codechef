#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
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
    int test_cases,ans,i,j,n,m,c;
    //cin>>test_cases;
    test_cases= fastRead_int();
    int p[101];
    int v[101];
    int x;
    int num_of_times[100];
    while(test_cases--)
    {
        ans=0;
        //scanf("%d %d",&n,&m);
        n= fastRead_int();
        m=fastRead_int();
        memset(num_of_times,0,sizeof(num_of_times));
        for(i=0;i<m;i++)
        {
            //scanf("%d",&x);
            x=fastRead_int();
            num_of_times[x]++;
        }
        for(i=0;i<n;i++)
        {
           // scanf("%d",&c);
           c=fastRead_int();
            for(j=0;j<c;j++)
            {
                //scanf("%d",&v[j]);
                v[j]=fastRead_int();
            }
            sort(v,v+c);
            for(j=c-1;j>=c-num_of_times[i]&&j>=0;j--)
            {
                ans=ans+ v[j];
            }
        }
        //cout<<ans<<endl;
        writeInt(ans);
    }

return 0;
}
