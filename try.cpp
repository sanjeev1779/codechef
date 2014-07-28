#include<iostream>
#include<string.h>
using namespace std;

main()
{
    string str,subsr;
    cin>>str;
    cout<<str[1]<<endl;
    cout<<strlen(str)<<"\n";
    subsr= str.substr(1,5);
    if(strcmp("sanjeev","sanjeev")==0)
    {
        cout<<"plz";
    }
    cout<<subsr;
}
