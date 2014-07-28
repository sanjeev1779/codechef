#include<stdio.h>
#include<math.h>
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
    int N,i,Q,L,R,j;
    N=fastread();
    int b[N];
    float C[N],maxm;
    //int L[N];

    for(i=0;i<N;i++)
    {
        b[i]=fastread();
    }



    Q=fastread();


    for(j=0;j<Q;j++)
    {
        L=fastread();
        R=fastread();
                int minm=b[L];
                for(i=L+1;i<=R;i++)
                {
                    if(b[i]<minm)
                        minm=b[i];
                }

                for(i=0;i<L;i++)
                {
                    C[i]= (minm+b[i]);
                }
                for(i=R+1;i<N;i++)
                {
                     C[i]= (minm+b[i]);
                }

                for(i=L;i<=R;i++)
                {
                    C[i]= (float)(minm+b[i])/(float)(2);
                }

                maxm=C[0];
                for(i=1;i<N;i++)
                {
                    if(C[i]>maxm)
                    maxm=C[i];
                }
                printf("%.1f\n",maxm);
    }

return 0;
}
