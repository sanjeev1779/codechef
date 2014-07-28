#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
main()
{
    int test_cases,l,b,i,sqrt_area,area;
    float rem;
    cin>>test_cases;
    while(test_cases--)
    {
        cin>>l>>b;
        area=l*b;
        sqrt_area= sqrt(area)+1;
        for(i=sqrt_area;i>=1;i--)
        {
            rem= (float)area/ (float)(i*i);
            if( ceil(rem)- floor(rem)==0)
            {
                cout<<rem<<endl;
                break;
            }
        }
    }

return 0;
}
