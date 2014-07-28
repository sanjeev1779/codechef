#include<stdio.h>
#include<math.h>
#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;

struct Point
{
    int x;
    int y;
};

// A globle point needed for  sorting points with reference to the first point
// Used in compare function of qsort()
Point p0;

// A utility function to find next to top in a stack
Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}

// A utility function to swap two points
int swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

// A utility function to return square of distance between p1 and p2
int dist(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

// A function used by library function qsort() to sort an array of
// points with respect to the first point
int compare(const void *vp1, const void *vp2)
{
   Point *p1 = (Point *)vp1;
   Point *p2 = (Point *)vp2;

   // Find orientation
   int o = orientation(p0, *p1, *p2);
   if (o == 0)
     return (dist(p0, *p2) >= dist(p0, *p1))? -1 : 1;

   return (o == 2)? -1: 1;
}

// Prints convex hull of a set of n points.
void convexHull(Point points[], int n)
{
   // Find the bottommost point
   int a[302][2];
   int ymin = points[0].y, min = 0;
   for (int i = 1; i < n; i++)
   {
     int y = points[i].y;

     // Pick the bottom-most or chose the left most point in case of tie
     if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
        ymin = points[i].y, min = i;
   }

   // Place the bottom-most point at first position
   swap(points[0], points[min]);

   // Sort n-1 points with respect to the first point.  A point p1 comes
   // before p2 in sorted ouput if p2 has larger polar angle (in
   // counterclockwise direction) than p1
   p0 = points[0];
   qsort(&points[1], n-1, sizeof(Point), compare);

   // Create an empty stack and push first three points to it.
   stack<Point> S;
   S.push(points[0]);
   S.push(points[1]);
   S.push(points[2]);

   // Process remaining n-3 points
   for (int i = 3; i < n; i++)
   {
      // Keep removing top while the angle formed by points next-to-top,
      // top, and points[i] makes a non-left turn
      while (orientation(nextToTop(S), S.top(), points[i]) != 2)
         S.pop();
      S.push(points[i]);
   }
    int k=0;
   // Now stack has the output points, print contents of stack
   while (!S.empty())
   {
       Point p = S.top();
      // cout << "(" << p.x << ", " << p.y <<")" << endl;
      a[k][0]= p.x, a[k][1]=p.y;
      k++;
       S.pop();
   }
   double sum=0;
    for(int i=0;i<k-1;i++)
    {
        sum+= sqrt( ( pow(a[i+1][1]-a[i][1], 2 ) + pow( a[i+1][0]- a[i][0], 2) )*1.0);
    }
    sum+= sqrt( ( pow(a[0][1]-a[k-1][1], 2 ) + pow( a[0][0]- a[k-1][0], 2) )*1.0);
    printf("%.2lf\n",sum);

    while(!S.empty())
        S.pop();
}

// Driver program to test above functions
int main()
{
   // Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
                       //{0, 0}, {1, 2}, {3, 1}, {3, 3}};

    int t,x1,i,y1,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        Point points[n+10];
        for(i=0;i<n;i++)
        {
            cin>>x1>>y1;
            points[i].x= x1;
            points[i].y=y1;
        }
        convexHull(points, n);
    }
return 0;
}
