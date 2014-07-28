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
int merge(LL arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    LL L[n1+1];
    LL R[n2+1];
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j <= n2; j++)
        R[j] = arr[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    int inverses=0;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            inverses+=(m-i);

        }
        k++;
    }


    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
return inverses;
}

int mergeSort(LL arr[], int l, int r)
{

    if (l < r)
    {
        int m = l+(r-l)/2;
        inverses=mergeSort(arr, l, m);
        inverses+=mergeSort(arr, m+1, r);
        inverses+=merge(arr, l, m, r);

    }
return inverses;
}


/* UITLITY FUNCTIONS */
/* Function to print an array */
void printArray(LL A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
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

        printf("%d\n",mergeSort(arr, 0, N-1));
        printf("\nSorted array is \n");
        printArray(arr, N);
    }
return 0;
}
