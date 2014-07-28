#include<stdio.h>
main()
{
    int N,Q,i,a,b,op,coun;
    scanf("%d %d",&N,&Q);
    int arr[N];
    for(i=0;i<N;i++)
    {
        arr[i]=0;//0 means tail
    }
    while(Q-->0)
    {
        coun=0;
        scanf("%d %d %d",&op,&a,&b);
        if(op==0)
        {
            for(i=a;i<=b;i++)
            {
                if(arr[i]==0)
                    arr[i]=1;
                else
                    arr[i]=0;
            }
        }
        else
            {
                for(i=a;i<=b;i++)
                {
                    if(arr[i]==1)
                    coun++;
                }
                printf("%d\n",coun);
            }

    }

return 0;
}
