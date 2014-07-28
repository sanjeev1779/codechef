#include<iostream>
using namespace std;

main()
{
    int N,i,Q,L,R,j;
    cin>>N;
    int b[N];
    float C[N],maxm;
    //int L[N];

    for(i=0;i<N;i++)
    {
        cin>>b[i];
    }



    cin>>Q;


    for(j=0;j<Q;j++)
    {
            cin>>Q>>R;
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
                printf("%f\n",maxm);
    }

return 0;
}
