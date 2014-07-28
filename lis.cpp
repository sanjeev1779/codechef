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

int binary_search(int A[], int l, int r, int key) {
    int m;

    while( r - l > 1 ) {
        m = l + (r - l)/2;
        (A[m] >= key ? r : l) = m; // ternary expression returns an l-value
    }

    return r;
}

int LIS(int A[], int n) {
    // Add boundary case, when array size is one

    int size=n;
    int store[size+1];
    int len; // always points empty slot

    memset(store, 0, sizeof(store[0])*size);

    store[0] = A[0];
    len = 1;
    for( int i = 1; i < size; i++ ) {
        if( A[i] < store[0] )
            // new smallest value
            store[0] = A[i];
        else if( A[i] > store[len-1] )
            // A[i] wants to extend largest subsequence
            store[len++] = A[i];
        else
            // A[i] wants to be current end candidate of an existing subsequence
            // It will replace ceil value in store
            store[binary_search(store, -1, len-1, A[i])] = A[i];
    }
    return len;
}

int main()
{

    int n,i;
    S(n);
    int a[n+1];

    for(i=0;i<n;i++)
        S(a[i]);
    printf("%d\n",LIS(a,n));
return 0;
}
