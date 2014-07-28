#include<iostream>
#include<math.h>
#include<stdio.h>
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
  int test_cases,i,diff,num;
  test_cases=fastread();
  while(test_cases--)
  {
      cin>>num;
      int a[num];
      a[0]=fastread();
      int maxm=0;
      for(i=1;i<num;i++)
      {
          a[i]=fastread();
          diff = a[i]-a[i-1];
          if( maxm <=diff)
          {
              maxm= diff;
          }
      }
      if(maxm>0)
         cout<<maxm<<endl;
      else
        cout<<"UNFIT\n";
  }

return 0;
}
