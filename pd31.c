#include<stdio.h>
main()
{
    int N,M,u,v,i;
    scanf("%d %d",&N,&M);
    for(i=0;i<M;i++)
    {
        scanf("%d %d",&u,&v);
    }

    if(N==M+1)
        printf("YES\n");
    else
            printf("NO\n");

return 0;
}
