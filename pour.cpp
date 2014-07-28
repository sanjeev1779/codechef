#include<iostream>
using namespace std;

int maxm(int a,int b)
{
    if(a>b)
        return a,b; //max=a and min=b;
    else return b,a; // max=b,and min=a;
}

main()
{
    int test_cases,a,b,c,b1,a1,b1_partial;
    cin>>test_cases;
    int ans;

    while(test_cases--)
    {
        ans=0;
        cin>>a>>b>>c;
        a,b=maxm(a,b);

        a1=0;
        b1=0;
        while(1)
        {
            if(a1==0)
            {
                a1=a; //if a1 is empty,then fill a
            }
            else if(b1==b)
            {
                b1=0; //if b is full,then empty b
            }
            else // pour a1 to b1
            {
                b1_partial=b1;
                if((b1_partial+a1)>=b)
                {
                        b1=b;
                        a1=a1-(b-b1_partial);
                }
                else
                {
                    b1=b1+a1;
                    a1=0;
                }
            }

            ans++;
        }
        cout<<ans<<endl;
    }

return 0;
}
