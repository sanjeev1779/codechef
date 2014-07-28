#include<stdio.h>
main()
{
    int N;
    scanf("%d",&N);
    int i;
    int p=0;
    char ch[1002];
    scanf("%s",ch);
    for(i=2;i*i<=N;i++)
    {
        if(N%i==0)
        {
            p=1;
            break;
        }
    }
    if(p==0)
        printf("YES\n");
    else
        printf("%s\n",ch);

return 0;
}
