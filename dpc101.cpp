#include<iostream>
using namespace std;
main()
{
    int i,a,b,coun,temp,carry,rem1,rem2,sum;
    while(1)
    {
        coun=0;
        cin>>a>>b;
        if(a==0 && b==0)
            break;
        if(b>a)
        {
            temp=b;
            b=a;
            a=temp;
        }
        carry=0;
        while(a>0)
        {
            rem1=a%10;
            rem2=b%10;

            sum=rem1+rem2+carry;
            if(sum>9)
            {
                coun++;
            }
            if(sum>9 && sum<20)
            {
                carry=1;
            }
            else if(sum>=20)
              {
                carry=2;
              }

            a=a/10;
            b=b/10;
        }

        if(coun==0)
        {
            cout<<"No carry operation.\n";
        }
        else if (coun==1)
            cout<<"1 carry operation.\n";
        else
            cout<<coun<<" carry operations.\n";
    }

return 0;
}
