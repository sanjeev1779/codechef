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
#define SL(N) scanf("%lld",&N);
#define pb push_back
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

inline void fastInput(int &x) {
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




int prefer[1010][506],N;
bool wPrefersM1OverM(int w, int m, int m1)
{
    for (int i = 0; i < N; i++)
    {
        if (prefer[w][i] == m1)
            return true;

        if (prefer[w][i] == m)
           return false;
    }
}

void stableMarriage()
{
    int wPartner[N];

    bool mFree[N];
    //cout<<N;
    memset(wPartner, -1, sizeof(wPartner));
    memset(mFree, false, sizeof(mFree));
    int freeCount = N;

    while (freeCount > 0)
    {
        int m;
        for (m = 0; m < N; m++)
            if (mFree[m] == false)
                break;
     //   cout<<"hi "<<m<<endl;
        for (int i = 0; i < N && mFree[m] == false; i++)
        {
            int w = prefer[m][i];

            if (wPartner[w-N] == -1)
            {
                wPartner[w-N] = m;
                mFree[m] = true;
                freeCount--;
            }

            else
            {

                int m1 = wPartner[w-N];

                if (wPrefersM1OverM(w, m, m1) == false)
                {
                    wPartner[w-N] = m;
                    mFree[m] = true;
                    mFree[m1] = false;
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
       cout<<(i+1 )<<" "<<(wPartner[i]+1)<< endl;
}

int main()
{
     // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
        int test_cases;
        fastInput(test_cases);
        int i,j,x;
        while(test_cases--)
        {
            memset(prefer,0,sizeof(prefer));
            fastInput(N);
            for(i=0;i<N;i++)
            {
                S(x);
                for(j=0;j<N;j++)
                 {
                       fastInput(prefer[i][j]);
                        prefer[i][j]+=N-1;
                    }
            }
            for(i=N;i<2*N;i++)
            {
                S(x);
                for(j=0;j<N;j++)
                    {
                        fastInput(prefer[i][j]);
                        prefer[i][j]+= -1;
                    }
            }
            stableMarriage();
        }


    return 0;
}
