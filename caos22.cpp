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

main()
{
    int test_cases,i,j,R,C,left[503][503],right[503][503],top,bottom,minm,minm1,minm2,x,y,k;
    int primes[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509};
    test_cases=fastRead_int();
    char str[503];
    int a[503][503];

    while(test_cases--)
    {
        R=fastRead_int();
        C=fastRead_int();
        vector<int>vech[R+1];
        vector<int>vecv[C+1];
        memset(a,0,sizeof(a));
        int k=0;

        for(j=1;j<=C;j++)
            vecv[j].pb(0);
        for(i=1;i<=R;i++)
        {
            fastRead_string(str);
            vech[i].pb(0);

            for(j=1;j<=C;j++)
            {

                if(str[j-1]=='^')
                   {
                       a[i][j]=1;

                   }
                else
                   {
                        a[i][j]=0;

                        vech[i].pb(j); //horizontal entry
                        vecv[j].pb(i); //vertical entry
                   }
            }
            vech[i].pb(C+1);
        }
          for(j=1;j<=C;j++)
            vecv[j].pb(R+1);

        int ans=0;
        int x=0;
        int y=0;
        for(i=1;i<=R;i++)
        {
            x=0;
            y=0;
            for(j=1;j<=C;j++)
            {
                    if(a[i][j]==1)
                    {

                        left[i][j]= j-vech[i][x]-1;
                        right[i][j]= vech[i][x+1]-j-1;


                    }
                    else
                    {
                            x++;
                    }


            }
        }

        for(i=1;i<=C;i++)
        {
            x=0;
            for(j=1;j<=R;j++)
            {
                if(a[j][i]==1)
                {

                    top= j-vecv[i][x]-1;
                    bottom= vecv[i][x+1]-j-1;
                    minm=min(left[j][i],min(right[j][i],min(top,bottom)));

                        for(k=0;primes[k]<=minm;k++)
                        {
                            ans++;
                        }
                }
                else
                    x++;
            }
        }
        writeInt(ans);
    }

return 0;
}
