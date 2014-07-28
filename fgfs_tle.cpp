#include<iostream>
#include<string.h>
#include<stdio.h>
#include<climits>
#include<map>
#include<algorithm>
#define LL  int
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%d",&N);
#define mp make_pair
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
    int t,i,x,z,N,ans,j;
    t= fastRead_int();
    LL cur_comp,K;
    LL last_finished;
    while(t--)
    {
        N=fastRead_int();
        K=fastRead_int();
        LL s[N+2];
        LL f[N+2];
        LL idx[N+2];
        pair<LL,int>par[N+2];
        pair<LL,LL>pa[N+2];
        for(i=1;i<=N;i++)
        {
           // SL(s[i]); SL(f[i]); S(idx[i]);
           s[i]= fastRead_int();
           f[i]= fastRead_int();
           idx[i]=fastRead_int();
            par[i]= mp(idx[i],i);
        }
        sort(par+1,par+N+1);
        ans=0;
        for(i=1;i<=N;)
        {
            cur_comp= par[i].first;
            x=0;
            while(cur_comp== par[i].first)
            {
                z= par[i].second;
                //cout<<z<<endl;
                pa[x]= mp(f[z],s[z]);
                x++;
                i++;
            }
            sort(pa,pa+x);

            if(x>0)
            {
                last_finished= pa[0].first;
                ans++;
            }
            for(j=1;j<x;j++)
            {
                if(pa[j].second>= last_finished)
                {
                    last_finished= pa[j].first;
                    ans++;
                }
            }
        }
        writeInt(ans);
    }
return 0;
}
