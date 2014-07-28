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
    int N,flag;
    LL a,b;

    S(N);
    LL minmx,minmy,i;
    string ch;
    vector<LL>vecx;
    vector<LL>vecy;
    while(N--)
    {
        cin>>ch;
        scanf("%lld %lld",&a,&b);
        if(ch=="add")
        {
            vecx.pb(a);
            vecy.pb(b);
        }
        else if(ch=="erase")
        {
            for(i=0;i<vecx.size();i++)
            {
                if(vecx[i]==a && vecy[i]==b)
                {
                     vecx.erase( vecx.begin()+i);
                     vecy.erase( vecy.begin()+i);
                }
            }
        }
        else
        {
            minmx=1000000001;
            minmy= 1000000001;
            flag=0;
            for(i=0;i<vecx.size();i++)
            {
                if(a<vecx[i] && b<vecy[i])
                {
                    minmx= min(vecx[i],minmx);
                    minmy= min(vecy[i],minmy);
                    flag=1;
                }
            }
            if(flag==1)
                printf("%lld %lld\n",minmx,minmy);
            else
                printf("-1\n");
        }

    }

return 0;
}
