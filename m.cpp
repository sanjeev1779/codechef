#include<stdio.h>
main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char s1[10100];
        char s2[10100];
        scanf("%s",s1);
        scanf("%s",s2);
        int a[300]={0};
        int b[300]={0};
        int i;
        for(i=0;i<strlen(s1);i++)
            a[(int)s1[i]]++;
        for(i=0;i<strlen(s2);i++)
            b[(int)s2[i]]++;
        long long int s;
        s=0;
        for(i=0;i<300;i++)
            {if(a[i]<b[i])
            s=s+a[i];
            else
            s=s+b[i];}
        printf("%lld\n",s);
    }
    return 0;

}
