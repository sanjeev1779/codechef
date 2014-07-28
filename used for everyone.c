#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
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
 int i,test_cases;
 cin>>test_cases;
 while(test_cases--)
 {

 }

return 0;
}
