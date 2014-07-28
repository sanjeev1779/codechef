#include<iostream>

int m,n,w[10],x[10]; //Global declaration of variables

using namespace std;
void sum_subset(int s,int k,int r)
{
                int i;
                x[k]=1;
                if(s+w[k]>=m)
                {
                                for(i=1;i<=n;i++)
                                {
                                                cout<<"x["<<i<<"]:"<<x[i]<<"\t";
                                }
                                cout<<"\n";
                }
                else
                {
                                if((s+w[k]+w[k+1])<=m)
                                {
                                                sum_subset(s+w[k],k+1,r-w[k]); //Recursive call
                                }
                }
                if(((s+r-w[k])>=m)&&((s+w[k+1])<=m))
                {
                                x[k]=0;
                                sum_subset(s,k+1,r-w[k]);
                }
}
main()
{


                //User input
                cout<<"Enter the no. of values :";
                cin>>n;
                cout<<"Enter the sum : ";
                cin>>m;
                cout<<"Enter the values :";
                int i;
                 int r;
                r=0;
                for(i=1;i<=n;i++)
                {
                                cin>>w[i];
                                r+=w[i];
                }
                sum_subset(0,1,r); //call the function to solve the sum of subsets problem

}
