#include<iostream>
using namespace std;

inline int fastread()
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

int pay( int a[],int n,int sum,int m,int k)
{
    if(m==0)
        return 1;
    else if(k>=n || m<0||m>sum)
            return 0;
    else
    {
        if(pay(a,n,sum-a[k],m,k+1)==1 || pay(a,n,sum-a[k],m-a[k],k+1)==1)
            return 1;
        else
            return 0;
    }
}

main()
{
    int n,m,i,test_cases,sum;
    test_cases=fastread();
    while(test_cases--)
    {
        cin>>n>>m;
        int a[n];
        sum=0;
        for(i=0;i<n;i++)
        {
            a[i]=fastread();
            sum+=a[i];
        }

        if(pay(a,n,sum,m,0)==1)
             cout<<"Yes\n";
        else
           cout<<"No\n";
    }

return 0;
}

//pay function to check whether he/she is able to pay or not
