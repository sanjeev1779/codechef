#include<math.h>
#include<cmath>
#include<stdio.h>
#include <iostream>
using namespace std;

// Define Infinite (Using INT_MAX caused overflow problems)
#define INF 10000
int k,r;
int points_arr[305][2];


// Prints convex hull of a set of n points.
void convexHull(int n)
{
    int a[302][2];
    // There must be at least 3 points
    if (n < 3) return;

    // Initialize Result
    int next[n+1];
    for (int i = 0; i < n; i++)
        next[i] = -1;

    // Find the leftmost point
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points_arr[i][0] < points_arr[l][0])
            l = i;

    // Start from leftmost point, keep moving counterclockwise
    // until reach the start point again
    int p = l, q;
    cout<<p<<" "<<endl;
    do
    {
        // Search for a point 'q' such that orientation(p, i, q) is
        // counterclockwise for all points 'i'
        q = (p+1)%n;

        for (int i = 0; i < n; i++)
        {
            int val = (points_arr[q][1] - points_arr[p][1]) * (points_arr[r][0] - points_arr[q][0]) -
              (points_arr[q][0] - points_arr[p][0]) * (points_arr[r][1] - points_arr[q][1]);
          if (val<0)
             q = i;
        }
        next[p] = q;  // Add q to result as a next point of p
        p = q; // Set p as q for next iteration
    } while (p != l);

    // Print Result
    k=0;
    for (int i = 0; i < n; i++)
    {
        if (next[i] != -1)
        {
           cout << "(" << points_arr[i][0] << ", " << points_arr[i][1]<< ")\n";
           a[k][0]= points_arr[i][0];
           a[k][1]= points_arr[i][1];
           k++;
        }
    }
    double sum=0;
    for(int i=0;i<k-1;i++)
    {
        sum+= sqrt( ( pow(a[i+1][1]-a[i][1], 2 ) + pow( a[i+1][0]- a[i][0], 2) )*1.0);
    }
    sum+= sqrt( ( pow(a[0][1]-a[k-1][1], 2 ) + pow( a[0][0]- a[k-1][0], 2) )*1.0);
    printf("%.2lf\n",sum);
}

// Driver program to test above functions
int main()
{
    int test_cases;
    cin>>test_cases;
    int n,i,x,y;
    while(test_cases--)
    {
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                scanf("%d %d",&points_arr[i][0],&points_arr[i][1]);
            }
        convexHull( n);

    }
return 0;
}
