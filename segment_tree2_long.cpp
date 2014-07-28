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

inline void writeInt(LL x)
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


inline void fastLongInput(LL &x) {
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


inline void fastIntInput(int &x) {
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




LL tree[1000010];
int MaxVal=1000010;
LL read(int idx)
{
    LL sum=0;
    while(idx>0)
    {
        sum+= tree[idx];
        idx-= (idx&-idx);
    }
    return sum;
}
void update(int idx,int val)
{
    while(idx<=MaxVal)
    {
        tree[idx]+=val;
        idx+= (idx&-idx);
        //cout<<"hi  "<<idx<<endl;
    }
}


main()
{
    int Q;
    int i,N,i1,i2;
    string str;
   fastIntInput(N);
   fastIntInput(Q);
    LL x;
    LL sum1,sum2,sum;
    for(i=1;i<=N;i++)
    {
        fastLongInput(x);
        update(i,x);
    }
    while(Q--)
    {
        cin>>str;
        fastIntInput(i1);
        fastIntInput(i2);
        if(str[0]=='S')
        {
            sum1= read(i2+1);
            if(i1==0)
                sum2=0;
            else
                sum2=read(i1);
            sum=sum1-sum2;
           writeInt(sum);
        }
        else if(str[0]=='G')
        {
            update(i1+1,i2);
        }
        else
            update(i1+1,-i2);
    }
return 0;
}
