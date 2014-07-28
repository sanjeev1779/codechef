#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define pb push_back
using namespace std;

int seg_arr[101];

// making the tree
int make_tree(int arr[], int seg_arr[],int seg_start, int seg_end, int index, int N)
{
    if(seg_start==seg_end)
    {
        seg_arr[index]= arr[seg_end];
       printf("seg_arr=%d: %d\n", index,seg_arr[index]);
        return arr[seg_end];
    }
    int seg_mid= seg_start+(seg_end-seg_start)/2;

    seg_arr[index]=make_tree(arr,seg_arr, seg_start,seg_mid,2*index+1,N)+make_tree(arr,seg_arr, seg_mid+1,seg_end,2*index+2,N);
    return seg_arr[index];
}

// find the sum of the array from query_start to query_end in the array
int get_sum(int arr[],int seg_arr[], int seg_start, int seg_end, int query_start, int query_end, int index,int N)
{
    if( query_start<=seg_start && seg_end<=query_end)
        return seg_arr[index];
    if( query_start> seg_end || seg_start>query_end)
        return 0;
    int seg_mid= ( seg_start+seg_end)/2;
    return get_sum(arr,seg_arr, seg_start,seg_mid,query_start,query_end,2*index+1,N) +  get_sum(arr,seg_arr, seg_mid+1,seg_end,query_start,query_end,2*index+2,N);

}

void update_tree(int arr[],int seg_arr[],int seg_start, int seg_end, int diff, int index, int N)
{
    if(index<seg_start || index> seg_end)
        return;
    seg_arr[index]+= diff;
    if(seg_start!= seg_end)
    {
        int mid= (seg_start+seg_end)/2;
        update_tree(arr, seg_arr,seg_start, mid, diff, 2*index+1,N);
        update_tree(arr, seg_arr,mid+1, seg_end, diff, 2*index+2,N);
    }
}

main()
{
    int N,i,index,val;
    cin>>N;
    int arr[N+1];
    memset(seg_arr,0,sizeof(seg_arr));
    for(i=0;i<N;i++)
    {
        S(arr[i]);
    }
    make_tree(arr,seg_arr,0,N-1,0,N);
   // for(i=0;i<N;i++)
     //   printf("%d  ",seg_arr[i]);
    int sum= get_sum(arr,seg_arr,0,N-1,0,N-1,0,N);
    cout<<sum<<endl;
    cout<<"Enter the index and its new value\n";
    cin>>index>>val;
    int diff= val-arr[index];
    update_tree(arr,seg_arr,0,N-1,diff,0,N);
    sum= get_sum(arr,seg_arr,0,N-1,0,N-1,0,N);
    cout<<sum<<endl;


return 0;
}

