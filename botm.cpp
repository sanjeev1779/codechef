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
#define mp make_pair
using namespace std;


int A[100005];
int partitions(int low,int high)
{
    int p=low,r=high,x=A[r],i=p-1;
    for(int j=p;j<=r-1;j++)
    {
        if (A[j]<=x)
        {

            i=i+1;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}
int selection_algorithm(int left,int right,int kth)
{
    for(;;)
    {
        int pivotIndex=partitions(left,right);          //Select the Pivot Between Left and Right
        int len=pivotIndex-left+1;

        if(kth==len)
            return A[pivotIndex];

        else if(kth<len)
            right=pivotIndex-1;

        else
        {
            kth=kth-len;
            left=pivotIndex+1;
        }
    }
}
main()
{
    int test_cases;
    S(test_cases);
    int N,i,median1,median2,median;
    LL moves,moves1,moves2;
    while(test_cases--)
    {
        S(N);
        moves=0;
        moves1=0;
        moves2=0;
        for(i=0;i<N;i++)
            S(A[i]);

        if(N%2)
        {
            median= selection_algorithm(0,N-1,N/2+1);
            //cout<<median;
            for(i=0;i<N;i++)
            {
                moves+= abs(median-A[i]);
            }
        }

        else
        {
            median1= selection_algorithm(0,N-1,N/2+1);
            median2= selection_algorithm(0,N-1,N/2);
            for(i=0;i<N;i++)
            {
                moves1+= abs(A[i]-median1);
                moves2+= abs(A[i]-median2);
            }
            moves= min(moves1,moves2);
        }
        printf("%lld\n",moves);
    }


return 0;
}
