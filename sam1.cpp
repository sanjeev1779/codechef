#include<iostream>
using namespace std;
int sum(int arr[][],int n)
{
    int x=0;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            x+= arr[i][j];
    return x;
}

main()
{
 int a,b;
 int arr[2][2];
 arr[0][0]=1;
 arr[0][1]=2;
 arr[1][0]=3;
 arr[1][1]=4;
 cout<<sum(arr,2);
}
