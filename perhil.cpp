#include<stdio.h>
#include<iostream>
using namespace std;
main()
{
    int test_case;
    cin>>test_case;
    int a,b,c;
    long long x,h;
    for(int i=1;i<=test_case;i++)
    {
        scanf("%d",&c);
        a=1,b=c-1;

        bool flag=false;

        while(a<b)
        {
            x=(a*a)+(b*b);
            h=c*c;
            if(x<h)
                a++;
            else if(x>h)
                b--;
            else
            {
                flag=true;
                break;
            }
        }
        if(flag)
            printf("PERFECT\n");
        else
            printf("IMPERFECT\n");
    }
    return 0;
}
