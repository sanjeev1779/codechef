
#include<stdio.h>
main()
{

int t,i,k,a[10001],n,num;
//printf("Enter the number of test cases\n");
scanf("%d",&t);

for(k=0;k<t;k++)
{
    for(i=0;i<10001;i++)
    a[i]=0;

   int max=0;

   scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        a[num]++;
    }

        for(i=0;i<10001;i++)
        {
            if(a[i]!=0)
            printf("%d %d\n",i,a[i]);
        }
//printf("%d %d\n",a[i],max);


}
return 0;
}
