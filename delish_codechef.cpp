#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

int find_max(int a[],int n, int start_index, int end_index)
{
    int maxm=a[start_index];
    int i;
    for(i=start_index+1;i<end_index;i++)
    {
        if(a[i]< maxm)
            maxm=a[i];
    }
    return maxm;
}

int kadane_for_max(int a[],int n,int start_index,int end_index)
{
    int max_so_far=0,max_end_here=0;
    int i;
    int flag=1;
    for(i=start_index;i<end_index;i++)
    {
        if(a[i]>0)
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
    {
        return find_max(a,n,start_index,end_index);
    }
    for(i=start_index;i<end_index;i++)
    {
        max_end_here+=a[i];
        if(max_end_here<0)
            max_end_here=0;
        else if(max_so_far < max_end_here)
            max_so_far=max_end_here;
    }
      return max_so_far;
}

int kadane_for_min(int a[],int n, int start_index, int end_index)
{//1 2 3 4
    int i;
    int t=a[start_index];
    int s=a[start_index];
    for(i=start_index+1 ; i < end_index;i++)
    {
        if(t+a[i]< a[i])
            t=t+a[i];
        else
            t=a[i];
        if(t<s)
        {
            s=t;
        }
    }
    return s;
}

int find_min_max(int a[],int n, int start_index, int end_index)
{
    int i;
    int minm=a[start_index];
    int maxm=a[start_index];
    for(i=1;i<end_index;i++)
    {
        if(a[i]<minm)
            minm=a[i];
        if(a[i]>maxm)
                maxm=a[i];
    }
    return abs(minm-maxm);
}

main()
{
    int n,i,ans,test_cases,j,a_max,b_max,a_min,b_min,maxm_diff;
    cin>>test_cases;
    while(test_cases--)
    {
        cin>>n;
        int a[n];
        int flag=1;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]>0)
                flag=0;
        }
        if(flag==5)
        {
               ans = find_min_max(a,n,0,n);
               cout<<ans<<endl;
        }

        else {
            //ans=kadane_for_max(a,n);
            //cout<<"The minm sub array= "<<kadane_for_min(a,n)<<endl;
            //j=0;
            int ans1=0;
            for(j=0;j<n-1;j++)
            {
                a_max= kadane_for_max(a,n,0,j+1);
                //cout<<j+1<<" a_max= "<<a_max<<endl;
                 b_min=kadane_for_min(a,n,j+1,n);
                //cout<<j+2<<" b_min= "<<b_min<<endl;
                 maxm_diff= abs(a_max- b_min);
                 if(maxm_diff > ans1)
                 {
                     ans1=maxm_diff;
                 }
            }

            int ans2=0;
            //cout<<"#################\n";
            for(j=0;j<n-1;j++)
            {
                a_min= kadane_for_min(a,n,0,j);
              //    cout<<j+1<<" a_min= "<<a_min<<endl;
                 b_max=kadane_for_max(a,n,j+1,n);
                //   cout<<j+2<<" b_max= "<<b_max<<endl;
                 maxm_diff= abs(a_min- b_max);
                 if(maxm_diff > ans2)
                 {
                     ans2=maxm_diff;
                 }
            }
          // cout<<"!!!!!!!\n";
            if(ans1>ans2)
                cout<<ans1<<endl;
            else
                cout<<ans2<<endl;
        }
    }
return 0;
}
