#include<iostream>
#include<string>
using namespace std;

main()
{
    int test_cases,rem;
    char ch[102];
    int p;
    cin>>test_cases;
    int c=0;
    while(test_cases--)
    {
        cin>>ch>>p;

        //check for p is cielnum2 or not
        int flag=1,a8=0,a5=0,a3=0;
        while(p>0)
        {
            rem=p%10;
            if(rem!=8 || rem!=5 || rem!=3)
            {
                flag=0;
                break;
            }
            else
            {
                if(rem==8)
                    a8++;
                else if(rem==5)
                    a5++;
                else
                    a3++;
            }
        }

        if(flag==1) // a ciel number
        {
            if(a8>=a5>=a3)
                c++;
        }
    }
    cout<<c<<endl;

 return 0;
}
