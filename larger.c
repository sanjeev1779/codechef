#include<stdio.h>
main()
{

    int N,i;
    float maxm;
    scanf("%d",&N);
    float C[N];
    for(i=0;i<N;i++)
    {
        scanf("%f",&C[i]);
    }
                maxm=C[0];
                for(i=1;i<N;i++)
                {
                   if(C[i]>maxm);
                    maxm=C[i];
                }
                printf("MAximum= %f\n",maxm);
}
