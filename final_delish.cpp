#include<iostream>
#include<stdio.h>
using namespace std;

#define max_size 2
int c[max_size];
int b[max_size];

int absolute(int num1,int num2)
{
    if(num1>num2)
        return (num1-num2);
    else
        return (num2-num1);
}
void kadane_for_max(int a[],int n,int start_index,int end_index)  //it doest not work for all -ve numbers so we have to find the maximum value of array
{
    c[0]=0;
    c[1]=0;

    int flag=1,i,index;
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
          //find the max value and its index
          int max_val= a[start_index];
          int index=0;
          for(i=start_index+1;i<end_index;i++)
          {
              if(a[i]> max_val)
              {
                  max_val=a[i];
                  index=i;
              }
          }
          c[0]=max_val;
          c[1]=index;
    }
    else
    {


            int max_so_far=0,max_end_here=0;
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
}


void kadane_for_min(int a[],int n, int start_index, int end_index)
{
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
    int test_cases,array_size,i,ans1,ans2,next_index,a_min,b_min,a_max,b_max;
    cin>>test_cases;
    while(test_cases--)
    {
        cin>>array_size;
        int a[array_size];

        for(i=0;i<array_size;i++)
        {
            cin>>a[i];
        }

        //find the barrier of the 2nd array and maxium sum sub array from 1st to (n-1)th element
       //           case1 maximize 1st part and minimize 2nd part
        kadane_for_max(a,array_size,0,array_size-1);
        a_max = c[0];
        next_index=c[1];
        kadane_for_min(a,array_size, next_index+1, array_size);
        b_min=b[0];
      //  cout<<a_max<<"and "<< b_min<<"\n";
       ans1= absolute(a_max,b_min);

        //case 2 minimize 1st part and maximize 2nd part

        kadane_for_min(a,array_size,0,array_size-1);
        a_min= b[0];
        next_index=b[1];

        kadane_for_max(a,array_size,next_index+1,array_size);
        b_max= c[0];

       // cout<<a_min<<"and "<< b_max<<"\n";
        ans2= absolute(b_max, a_min);

        if(ans1>ans2)
            cout<<ans1<<endl;
        else
            cout<<ans2<<endl;
    }

return 0;
}
