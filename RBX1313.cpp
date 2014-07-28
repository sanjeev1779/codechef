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

main()
{
    int N,i;
    S(N);
    LL fibo[100];
    fibo[0]=0;
    fibo[1]=1;
    fibo[2]=1;
    fibo[3]=2;
    i=3;
    for(i=3;i<30;i++)
    {
        fibo[i]=fibo[i-1]+fibo[i-2];
        // cout<<"i="<<i<<"and "<<fibo[i]<<endl;
    }
    LL x,y;

    for(i=0;;i++)
    {

        if(N<=fibo[i])
        {
            x=fibo[i]-N;
            y=N-fibo[i-1];
            if(x==y)
                cout<<fibo[i]<<endl;
            else if(x<y)
                cout<<fibo[i]<<endl;
            else
                cout<<fibo[i-1]<<endl;
                break;

        }
    }

return 0;
}
