#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#define LL long long
using namespace std;
main()
{

    int i=0,N,curr_sum=0;
    cin>>N;
    int array[N];
    int max_front[N];
    memset(max_front,0,sizeof(max_front));
    while(i<N)scanf("%lld",&array[i++]);
    i=0;
    int max_=array[0];
    while(i<N) {
                        if(curr_sum+array[i]>=0)
                            {
                                if(curr_sum<0)
                                    curr_sum=array[i];
                                else
                                    curr_sum+=array[i];
                            }
                        else
                            {
                                curr_sum=array[i];
                            }
                        max_front[i]=max_=max(max_,curr_sum);
                        i++;
                }
                i=0;
                while(i<N)cout<<max_front[i++]<<"\t";
return 0;
}
