
#include<string.h>
#include<stdio.h>

#define LL long long

main()
{
 int test_cases;
 LL N,K;
scanf("%d",&test_cases);
while(test_cases--)
{
   // cin>>N>>K;
   scanf("%lld %lld",&N,&K);
    if(N!=0 && K!=0)
    {
        cout<<N/K<<" "<<N%K<<endl;
    }
    else
    {
        if(K==0)
            cout<<0<<" "<<N<<endl;
        else
            cout<<"0 0\n";
    }
}

return 0;
}
