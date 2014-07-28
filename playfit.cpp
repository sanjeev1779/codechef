#include<iostream>
#include<math.h>
#include<stdio.h>
#include<vector>
using namespace std;



main()
{

  int test_cases,i,diff,n;
  cin>>test_cases;
  while(test_cases--)
  {
      cin>>n;
      vector<int> a(n, 0);
      for(i=0;i<n;i++)
      {
          cin>>a[i];
      }

      for(i=0;i<n-1;i++)
      {
        int maxm = max_element(a.begin(), a.end());
        printf("%d\n",maxm);
      }
      if(maxm>0)
         cout<<maxm<<endl;
      else
        cout<<"UNFIT\n";
  }

return 0;
}
