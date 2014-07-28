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
int arr[1000010];
int getMid(int s, int e) {  return s + (e -s)/2;  }

LL getSumUtil(int *st, int ss, int se, int qs, int qe, int index)
{

    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return 0;


    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*index+1) +
           getSumUtil(st, mid+1, se, qs, qe, 2*index+2);
}

void updateValueUtil(int *st, int ss, int se, int i, int diff, int index)
{

    if (i < ss || i > se)
        return;

    st[index] = st[index] + diff;
    if (se != ss)
    {
        int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*index + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*index + 2);
    }
}
void updateValue(int arr[], int *st, int n, int i, int new_val,int diff1)
{
    if (i < 0 || i > n-1)
    {
        return;
    }
    int diff=diff1;
    updateValueUtil(st, 0, n-1, i, diff, 0);
}

LL getSum(int *st, int n, int qs, int qe)
{

    if (qs < 0 || qe > n-1 || qs > qe)
    {
        return -1;
    }

    return getSumUtil(st, 0, n-1, qs, qe, 0);
}

int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{

    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }


    int mid = getMid(ss, se);
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) +
              constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}

int *constructST(int arr[], int n)
{

    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
    int *st = new int[max_size];


    constructSTUtil(arr, 0, n-1, st, 0);
    return st;
}

int main()
{
    int n,q,i;
    string ch;
    int n1,n2;
    S(n);S(q);

    for(i=0;i<n;i++)
        S(arr[i]);

    int *st = constructST(arr, n);
    while(q--)
    {
            cin>>ch>>n1>>n2;
            if(ch[0]=='S' || ch[0]=='s')
                printf("%lld\n", getSum(st, n, n1, n2));
            else if(ch[0]=='G' || ch[0]=='g'){
                    arr[n1]= arr[n1]+n2;
                updateValue(arr, st, n, n1, arr[n1],n2);
            }
            else if(ch[0]=='T' || ch[0]=='t')
            {
                arr[n1]= arr[n1]-n2;
                    updateValue(arr, st, n, n1, arr[n1],-n2);
            }
    }
return 0;
}
