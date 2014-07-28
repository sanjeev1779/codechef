#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;

template<class T>
class BIT
{
      T *tree;
      int maxVal;
      public:
      BIT(int N)
      {
              tree = new T[N+1];
              memset(tree,0,sizeof(T)*(N+1));
              maxVal = N;
      }
      void update(int idx, T val)
      {
           while (idx <= maxVal)
           {
                 tree[idx] += val;
                 idx += (idx & -idx);
           }
      }
      //Returns the cumulative frequency of index idx
      T read(int idx)
      {
        T sum=0;
        while (idx>0)
        {
              sum += tree[idx];
              idx -= (idx & -idx);
        }
        return sum;
      }
};

int main()
{
    int a[100],cur=1,mul=2,add=19,MAX=65536,x,i;
    //Initialize the size by the
    //maximum value the tree can have
    BIT<int> B(MAX);
    for (i=0;i<5;i++)
    {
        cin>>x;
        a[i] = x;
        B.update(a[i],x);
        cur = ((cur * mul + add) % MAX);
    }
    printf("upateed\n");
    while (cin>>x)
    {
          cout<<B.read(x)<<endl;
    }

}
