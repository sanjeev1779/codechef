#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;




main()
{
    int test_cases,rem,k,i,num;
    cin>>test_cases;
    while(test_cases--)
    {
        scanf("%d",&k);
        int a[k];
        if(k==0)
        {
            cout<<"3\n";
        }

        else
        {
            rem=4687;
            for(i=0;i<k;i++)
            {
                num=rem*10;
                a[i]=num/33102;
                rem=num%33102;
            }
            printf("3.");
            for(i=0;i<k;i++)
            {
                printf("%d",a[i]);
            }
            printf("\n");
        }

    }
return 0;
}
