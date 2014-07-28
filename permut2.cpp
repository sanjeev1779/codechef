#include<iostream>
#include<stdio.h>
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
    int num,i,j,k;
    while(1)
    {
        num=fastread();
        //cin>>num;
        if(num==0)
            {
                break;
            }
        else
            {
                int flag=1;
                int a[num+1];
                int b[num+1];
                a[0]=b[0]=0;
                for(i=1;i<=num;i++)
                {
                    a[i]=fastread();
                   // cin>>a[i];
                    //b[a[i]]=i;
                }
                i=1;
                while(i<=num)
                {
                    if(a[a[i]]!=i)
                    {
                        flag=0;//not ambigous
                        break;
                    }
                    i++;
                }
                if(flag==0)
                {
                    cout<<"not ambiguous\n";
                }
                else
                    cout<<"ambiguous\n";
            }
    }

return 0;
}
