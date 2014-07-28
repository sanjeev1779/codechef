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
        int l1=strlen(s1), l2= strlen(s2);
        for(i=0;i<l1;i++)
            a[s1[i]]++;
        for(i=0;i<l2;i++)
            b[s2[i]]++;
        int s;
        s=0;
        for(i=0;i<300;i++)
            {if(a[i]<b[i])
            s=s+a[i];
            else
            s=s+b[i];}
        printf("%d\n",s);
    }
    return 0;
}
