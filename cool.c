
#include<string.h>
#include<stdio.h>
#include<math.h>
#define LL long long

/*
inline void fastLongInput(long long &x) {

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
*/
LL gcd(LL a,LL b)
{
   if(a%b==0)
     return b;
   else return gcd(b,a%b);
}
main()
{
     int test_cases;
    //S(test_cases);
    scanf("%d",&test_cases);
    LL N,ans,gc,den,i;
    LL start_index;
    LL x;
    while(test_cases--)
    {
        ans=0;
        scanf("%lld",&N);
       //fastLongInput(N);
        x=sqrt(N);
        for(i=1;i<=x;i++)
        {
            ans+= (N/i);
           // cout<<i<<"   :   "<<N/i<<endl;
        }
     //   cout<<ans<<endl;
       ans= (ans<<1) - x*x;
            den= N*N;
         //  printf("ans= %lld , den=%lld\n",ans,den);
            gc= gcd(ans,den);
            printf("%lld/%lld\n",ans/gc,den/gc);
    }


return 0;
}
