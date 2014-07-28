#include<iostream>
#include<algorithm>
#include<stdio.h>
#define max_size 2
using namespace std;
int c[max_size];
int b[max_size];

void kadane_for_max(int a[],int n,int start_index,int end_index)
{
    c[0]=0;
    c[1]=0;
    int max_so_far=0,max_end_here=0;
    int i,index;

            for(i=start_index;i<end_index;i++)
            {
                max_end_here+=a[i];
                if(max_end_here<0)
                    max_end_here=0;
                else if(max_so_far < max_end_here)
                   {
                       max_so_far=max_end_here;
                       index=i;
                   }
            }
             c[0]= max_so_far;
             c[1]= index;

}
        void kadane_for_min(int a[],int n, int start_index, int end_index)
        {//1 2 3 4
            b[0]=0;
            b[1]=0;
            int i,index=start_index;
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
                    index=i;
                }
            }
            b[0]=s;
            b[1]=index;
            //cout<<"asdnka=" <<index<<"\n";
    //return b;
        }

main()
{
    int n,i,ans1,ans2,test_cases,j,a_max,b_max,a_min,b_min,next_index,index1,index2;
    cin>>test_cases;
    while(test_cases--)
    {
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }

                kadane_for_max(a,n,0,n-1);
                a_max=c[0];
               int next_index1=c[1];
               //cout<<" a_max= "<<a_max<<"and next index= "<<next_index1<<endl;
                 kadane_for_min(a,n,next_index1+1,n);
                 b_min=b[0];
                 index1=b[1];
              //  cout<<" b_min= "<<b_min<<"and next index= "<<index1<<endl;
                ans1= abs(a_max- b_min);
                cout<<"a_max= "<<a_max <<"   b _min = "<<b_min<<" ans=" <<ans1<<endl;


            //cout<<"#################\n";
                kadane_for_min(a,n,0,n-1);
                a_min=b[0];
              int next_index2=b[1];
            // cout<<" a_min= "<<a_min<<"and next index= "<<next_index2<<endl;
                 kadane_for_max(a,n,next_index2+1,n);
                 b_max=c[0];
                 index2=c[1];
              //  cout<<" b_max= "<<b_max<<"and next index= "<<index2<<endl;
                 ans2= abs(a_min- b_max);
                 cout<<"a_min= "<<a_min <<"  b _max = "<<b_max<<"  ans=" <<ans2<<endl;

          // cout<<"!!!!!!!\n";
            if(ans1>ans2)
                cout<<ans1<<endl;
            else
                cout<<ans2<<endl;
        }
return 0;
}
