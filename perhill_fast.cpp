#include<iostream>
#include<stdio.h>
using namespace std;
main()
{
    int t;
    scanf("%d",&t);
    long long h,i,x;
    int p,c,a,b;
    for(int j=0;j<t;j++)
    {
        p=1;
        scanf("%d",&c);
        h=c*c;
        a=c;
        b=1;
        while(a>b)
        {
            x= a*a+b*b;
            if(x>h)
                a--;
            else if(x<h)
                b++;
            else if(x==h)
            {
                p=0;
                cout<<a<<" "<<b<<endl;
                break;
            }

        }
        if(p==0)
            printf("PERFECT\n");
        else
            printf("IMPERFECT\n");
    }


return 0;
}
