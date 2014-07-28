#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#define LL long long
using namespace std;
main()
{
    int test_cases,A,ran,B,K,num,org_num,c,i,j;
    cin>>test_cases;
    int a[1000];
    while(test_cases--)
    {
        cin>>A>>B>>K;
        int ans=0;
        for(num=A;num<=B;num++)
        {
            ran=0;
            org_num=num;
            c=0;
            memset(a,0,sizeof(a));
            for(i=2;i*i<=num;i++)
            {
                while(num%i==0)
                {
                    num=num/i;
                    a[i]++;
                    ran= max(ran,i);
                }
            }
            if(num!=1)
            {
                a[num]++;
                ran=max(ran,num);
            }
            for(i=2;i=ran;i++)
            {
                if(a[i]>0)
                    c++;
            }
            if(c==K)
                ans++;
        }
        cout<<ans<<endl;
    }
return 0;
}
