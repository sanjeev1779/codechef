#include<iostream>
#include<algorithm>
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

main()
{
    int test_cases,N,i,minm,div;
    test_cases=fastread();
    while(test_cases--)
    {
        N=fastread();
        int a[N];
        cin>>a[0];
        minm=a[0];
        for(i=1;i<N;i++)
        {
            a[i]=fastread();
            if(a[i]<minm)
                minm=a[i];
        }
        while(1)
        {
                int flag=1;

                    for(i=0;i<N;i++)
                    {
                        if(a[i]%minm!=0)//maxm is not gcd
                        {
                            flag=0;
                            minm=minm-1;
                        }
                    }
                        if(flag==1)
                            {
                                div=minm;
                                break;
                            }

        }
        //cout<<"minm= "<<minm<<"\n";
        for(i=0;i<N;i++)
          cout<<a[i]/div<<" ";
        cout<<endl;

    }

return 0;
}
