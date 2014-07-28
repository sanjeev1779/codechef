#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define pb push_back
#define VI vector<int>
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked
using namespace std;
inline void writeInt(long long int x)
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
inline void fastLongInput(int &x) {

    register int c = getchar();

    x = 0;

    int neg = 0;



    for(; ((c<48 || c>57) && c != '-'); c = getchar());



    if(c=='-') {

        neg = 1;

        c = getchar();

    }



    for(; c>47 && c<58 ; c = getchar()) {

        x = (x<<1) + (x<<3) + c - 48;

    }



    if(neg)

        x = -x;

}

inline void fastRead_string(char *str)
{
    register char c = 0;
    register int i = 0;
    while (c < 33)
        c = getchar_unlocked();
    while (c != '\n') {
        str[i] = c;
        c = getchar_unlocked();
        i = i + 1;
    }
    str[i] = '\0';
}


vector<VI>vec(10002);
main()
{
    int n,idx,a,b,s,M,k,q,i;
    LL amount;
    S(n);
    S(q);
    char ch[20];
    s=0;
    while(q--)
    {
        fastRead_string(ch);

        if(ch=="UPDATE")
        {
          //  cout<<"hi"<<endl;
          // scanf("%d %d",&a,&b);
          fastLongInput(a);
          fastLongInput(b);

           vec[s].pb(a);
           vec[s].pb(b);
           s++;
        }
        else
        {
            amount=0;
            //scanf("%d",&idx);
            fastLongInput(idx);
           // cout<<"sL :"<<s<<endl;
            for(i=0;i<s;i++)
            {
                //cout<<"val: "<<vec[i][0]<<endl;
                if(idx%vec[i][0]==0)
                    amount+=vec[i][1];
            }
            //printf("%lld\n",amount);
            writeInt(amount);

        }
    }

return 0;
}
