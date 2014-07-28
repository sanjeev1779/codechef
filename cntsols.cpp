#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define pb push_back
#define inf 1000000007
using namespace std;

LL fast_pow(LL a,LL d,LL mod)
{
  LL mul=1;
    while(d>0)
    {
      switch(d%4)
      {
        case 3: mul= (mul*a)%mod;
        case 2: mul= (mul*a)%mod;
        case 1: mul= (mul*a)%mod;
      }
      d/=4;
      a=((((((a*a)%mod)*a)%mod)*a)%mod);
    }

  return  (LL) (mul%mod);
}

main()
{

    int i,j,k,n,m;
    LL upper,d,val,soln;
    int test_Cases,ans;
    cin>>test_Cases;
    while(test_Cases--)
    {
        vector<int>first,second,third;
            cin>>upper>>d>>m>>n;
        int freq[41];
        memset(freq,0,sizeof(freq));
        if(d>0)
        {
            int ans=0;
            minm= min(upper,n-1);
            for(i=0;i<=minm;i++)
            {
                for(j=0;j<=minm;j++)
                {
                    for(k=0;k<=minm;k++)
                    {
                        //val = pow(i,d)+pow(j,d)+pow(k,d);
                        val[]
                        if( val %n==m)
                        {
                          //  printf("%d %d %d\n",i,j,k);
                            ans++;
                            first.pb(i);
                            second.pb(j);
                            third.pb(k);
                            freq[i]++;
                            freq[j]++;
                            freq[k]++;
                        }
                    }
                }
            }
            //cout<<ans<<endl;
            soln=0;
            for(i=0;i<ans;i++)
            {

                if(first[i]==upper || second[i]==upper || third[i] ==upper)
                    {
                        printf("%d %d %d\n",first[i],second[i],third[i]);
                        soln++;
                    }
            }
            cout<<soln<<endl;
        }
        else
        {
            val= 3;
            if(val%n==m)
               {
                   ans= fast_pow(upper,3,inf);
            else
                ans=0;
            cout<<ans<<endl;
        }
    }
return 0;
}
