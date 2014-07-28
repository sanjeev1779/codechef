#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<climits>
#include<map>
#include<math.h>
#include<algorithm>
#define LL int
#define P(N) printf("%d\n",N);
#define SL(N) scanf("%d",&N);
#define S(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
#define pll pair<LL,LL>
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

inline int get()
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


int get1()
{
  char c;
  while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
  bool flag=(c=='-');
  if(flag)
    c=getchar();
  int x=0;
  while(c>='0'&&c<='9')
    {
      x=x*10+c-48;
      c=getchar();
    }
  return flag?-x:x;
}
main()
{
       int t,i,N,ans=0,j,k;
       t= get();
       LL s,f,K,last_finish,px;
       while(t--)
       {
            N= get(); K= get();
            pair<LL,LL>temp;
            pair<LL,pll >p[N+1];
            for(i=0;i<N;i++)
            {
                //SL(s) SL(f) SL(px);
                s= get(); f= get(); px= get();
                temp=mp(s,f);
                p[i]= mp( px,temp);
                //cout<<"hi\n";
            }
            sort(p,p+N);
           // for(i=0;i<N;i++)
             //   printf("%lld  ",p[i].first);
            //cout<<endl;
            ans=0;
            for(i=0;i<N;)
            {
                 pair<LL,LL>pa[N+1];
                k=0;
                for(j=i;j<N;)
                {
                  //  cout<<i<<" = "<<p[i].first<<" and "<<j<<" = "<<p[j].first<<endl;
                    if(p[i].first==p[j].first)
                    {
                        temp= p[j].second;
                        pa[k]= mp(temp.second, temp.first);
                        k++;
                        j++;
                    }
                    else
                    {
                        i=j;
                        break;
                    }

                }
                if(j==N)
                    i=N;
                //cout<<i<<" i and k"<<k<<endl;
                sort(pa,pa+k);
                //for(int x= 0;x<k;x++)
                  //  cout<<pa[x].second<<" "<<pa[x].first<<endl;
                //cout<<"start shcude\n";
                if(k>0)
                    {
                        ans++;
                        last_finish= pa[0].first;
                    //     cout<<pa[0].second<<" "<<pa[0].first<<endl;
                    }
                for(j=1;j<k;j++)
                {
                  //  cout<<pa[j].second<<" "<<pa[j].first<<endl;
                //    cout<<"sdmsandm j "<<j<<endl;
                    if(pa[j].second>= last_finish) // take it
                    {
                        last_finish= pa[j].first; // book til pa[j].first
                        ans++;
                    }
                }
              //  cout<<"i "<<i<<" and ans= "<<ans<<endl;

            }
            writeInt(ans);
       }
return 0;
}
