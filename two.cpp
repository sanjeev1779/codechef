#include <stdio.h>
#include<iostream>
using namespace std;
#include<algorithm>
#define MAX 100000

void printPairs(int arr[], int arr_size, int sum)
{
  int i, temp;
  bool binMap[MAX] = {0}; /*initialize hash map as 0*/

  for(i = 0; i < arr_size; i++)
  {
    temp = sum - arr[i];
    if(temp >= 0 && binMap[temp] == 1)
    {
      cout<<min(i,arr_size-1-i);
      break;
    }
    binMap[arr[i]] = 1;
  }
}

/* Driver program to test above function */
int main()
{
    int A[] = {3,3,3,2,4};
    int n = 6;
    int arr_size = 6;

    printPairs(A, arr_size, n);

    getchar();
    return 0;
}
