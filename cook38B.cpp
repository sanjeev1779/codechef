#include<stdio.h>
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


inline void fastLongInput(LL  &x) {

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


inline void fastLongInput1(int &x) {

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



LL gcd(LL a,LL b)
{
    LL c;

    if ( b == 0 )
        return a;

    else
        while ( b != 0 )
        {
            c = b;
            b = a % b;
            a = c;
        }

        return a;
}
int factors(LL num)
{
    int cnt=0;
    int i;
    for(i=1;i*i<=num;i++)
    {
        if(num%i==0)
        {
            cnt++;
        }
        if(i*i!=num)
           cnt++;
    }
    return cnt;
}
main()
{

    int test_Cases;
    fastLongInput1(test_Cases);
    LL n,m,gc;
    int y;
    while(test_Cases--)
    {
        fastLongInput(n);
        fastLongInput(m);
            gc= gcd(n-1,m-1);

           // printf("%lld\n",gc+1);
           writeInt(gc+1);
    }
return 0;
}
