#include<iostream>
using namespace std;

main()
{
    int i,n,j,coun;
    int a[42];
    for(i=0;i<10;i++)
    {
        coun=0;
        for(j=0;j<42;j++)
        {
            a[j]=0;
        }


        for(j=0;j<10;j++)
        {
            cin>>n;
            a[n%42]+=1;
        }



        for(j=0;j<42;j++)
        {
            if(a[j]>=1)
            {
                coun++;
            }
        }
        cout<<coun<<endl;
    }

return 0;
}
