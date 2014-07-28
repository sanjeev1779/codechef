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
    int test_cases,i,j,k,x,b_index,c_index,n,m;
    test_cases=fastread();
    while(test_cases--)
    {
        cin>>n>>m;
        int a[m];
        int b[n-m];
        int c[n-m];
        for(i=0;i<m;i++)
        {
            a[i]=fastread();
        }
        sort(a,a+m);
        j=0;
        x=0;
        b_index=0;
        c_index=0;
        for(i=1;i<=n;i++)
        {
            if(a[j]==i)
            {
                j++;
            }
            else //assign task to each member
            {
                    if(x%2==0)//assgin to chef
                    {
                        b[b_index]=i;
                        b_index++;
                    }
                    else //asign task to assistant
                    {
                        c[c_index]=i;
                        c_index++;
                    }
                    x++;
            }
        }

        for(i=0;i<b_index;i++)
        {
            cout<<b[i]<<" ";
        }
          cout<<"\n";

        for(i=0;i<c_index;i++)
        {
            cout<<c[i]<<" ";
        }
          cout<<"\n";
    }

return 0;
}
