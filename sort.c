#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main()
{

    int n,i;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    qsort(a,a+n);
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);
}
