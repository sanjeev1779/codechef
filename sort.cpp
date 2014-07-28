#include<iostream>
#include<algorithm>
using namespace std;
main()

{
    int N,i;
    cin>>N;
    int a[N];
    for(i=0;i<N;i++)
    cin>>a[i];

    sort(a,a+N);
    for(i=0;i<N;i++)
        cout<<a[i]<<" ";
}
