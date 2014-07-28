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
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;

int merge(LL arr[], LL temp[], int left, int mid, int right)
{
  int i, j, k;
  int inv_count = 0;

  i = left;
  j = mid;
  k = left;
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
      inv_count = inv_count + (mid - i);
    }
  }
  while (i <= mid - 1)
    temp[k++] = arr[i++];

  while (j <= right)
    temp[k++] = arr[j++];

  for (i=left; i <= right; i++)
    arr[i] = temp[i];

  return inv_count;
}

int _mergeSort(LL arr[], LL temp[], int left, int right)
{
  int mid, inv_count = 0;
  if (right > left)
  {
    mid = (right + left)/2;

    inv_count  = _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid+1, right);
    inv_count += merge(arr, temp, left, mid+1, right);
  }
  return inv_count;
}
int mergeSort(LL arr[], int array_size)
{
    LL temp[array_size+1];
    return _mergeSort(arr, temp, 0, array_size - 1);
}


main()
{
    int test_cases,N,i;
    S(test_cases);
    LL arr[10002];
    while(test_cases--)
    {
        S(N);
        for(i=0;i<N;i++)
            SL(arr[i]);

        printf("%d\n",mergeSort(arr,N));
    }
return 0;
}
