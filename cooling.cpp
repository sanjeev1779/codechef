#include<iostream>
#include<algorithm>
using namespace std;
inline int fastread()
    {
    int noRead=0;
    char p=getchar_unlocked();
    for(;p<33;){p=getchar_unlocked();};
    while(p>32)
    {
    noRead = (noRead << 3) + (noRead << 1) + (p - '0');
    p=getchar_unlocked();
    }
    return noRead;
    };


main()
{
    int i,test_cases,N,j,k;
    test_cases=fastread();
    while(test_cases--)
    {
        N=fastread();
        int W[N],M[N];
        for(i=0;i<N;i++)
        {
            W[i]=fastread();
        }
        for(j=0;j<N;j++)
        {
            M[j]=fastread();
        }
        sort(W,W+N);
        sort(M,M+N);

          j=0;
          i=0;
        while(j<N)
        {
            if(W[i]<=M[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        cout<<i<<endl;
    }

return 0;
}
