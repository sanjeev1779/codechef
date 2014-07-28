#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

main()
{
    int test_cases,R,x1,y1,x2,y2,x3,y3;
    double d12,d13,d23;
    cin>>test_cases;
    while(test_cases--)
    {
        cin>>R;
        cin>>x1>>y1;
        cin>>x2>>y2;
        cin>>x3>>y3;

        d13=sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3));

        if(d13<=R)
        {
            cout<<"yes\n";
        }
        else
        {
            d12=sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
            d23=sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3));

            if( d12<=R && d23<=R)
            {
                cout<<"yes\n";
            }
            else
                cout<<"no\n";

        }
    }

return 0;
}
