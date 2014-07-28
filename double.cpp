#include<iostream>
using namespace std;
inline int fastread()
{
        int noRead=0;
        char p=getchar_unlocked();
        for(; p<33;) {
                p=getchar_unlocked();
        };
        while(p>32) {
                noRead = (noRead << 3) + (noRead << 1) + (p - '0');
                p=getchar_unlocked();
        }
        return noRead;
};

main()
{

    int test_cases,num;
    test_cases=fastread();
    while(test_cases--)
    {

        num=fastread();
        if(num%2==0)
            cout<<num<<endl;
        else
            cout<<(num-1)<<endl;
    }

return 0;
}
