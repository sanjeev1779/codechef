#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
using namespace std;
main()
{
  LL x,y,x1,x2,y1,y2;
  cin>>x>>y;
  LL mod= abs(x)+abs(y);
  if(x>0 && y>0)
    cout<<"0 "<<mod<<" "<<mod<<" 0\n";
  else if(x<0 && y>0)
    cout<<-mod<<" 0 0 "<<mod<<"\n";
  else if(x>0 && y<0)
    cout<<"0 "<<-mod<<" "<<mod<<" 0\n";
  else
    cout<<-mod<<" 0 0 "<<-mod<<endl;

return 0;
}
