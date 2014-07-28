#include<iostream>
using namespace std;
main()
{
    int i,test_cases,n,num,j;
    int dig[7];

    cin>>test_cases;
    while(test_cases--)
    {
        cin>>n;
        num=n;
        i=0;
        while(n>0)
        {
            dig[i]=n%10;
            n=n/10;
            i++;
        }
        for(j=i-1;j>=0;j--)
        {
            if(dig[j]>=3)
            {
                dig[j]=3;
                int x=j;
                for(x=j-1;x>=0;x--)
                {
                    dig[x]=3;
                }
                break;
            }

            else
            {
                dig[j]=1;
            }
        }

        for(j=i-1;j>=0;j--)
        {
            cout<<dig[j];
        }

         cout<<endl;
    }

return 0;
}
