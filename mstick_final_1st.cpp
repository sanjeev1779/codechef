#include <stdio.h>
#include <math.h>
#include <limits.h>


inline int fastread()
{
        int noRead=0;
        char p=getchar_unlocked();
        for(; p<33;) {
                p=getchar_unlocked();
        };
        while(p>32) {
                noRead = (noRead << 3) + (noRead << 1) + (p - '0');
                p=getchar_unlocked();
        }
        return noRead;
};


//rmq algo

int minVal(int x, int y)
{
        return (x < y)? x: y;
}

int getMid(int s, int e)
{
        return s + (e -s)/2;
}

int RMQUtil(int *st, int ss, int se, int qs, int qe, int index)
{
        if (qs <= ss && qe >= se)
                return st[index];

        if (se < qs || ss > qe)
                return INT_MAX;

        int mid = getMid(ss, se);
        return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),
                      RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
}

int RMQ(int *st, int n, int qs, int qe)
{
        if (qs < 0 || qe > n-1 || qs > qe) {
                printf("Invalid Input");
                return -1;
        }

        return RMQUtil(st, 0, n-1, qs, qe, 0);
}

int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
        if (ss == se) {
                st[si] = arr[ss];
                return arr[ss];
        }

        int mid = getMid(ss, se);
        st[si] =  minVal(constructSTUtil(arr, ss, mid, st, si*2+1),
                         constructSTUtil(arr, mid+1, se, st, si*2+2));
        return st[si];
}


int *constructST(int arr[], int n)
{

        int x = (int)(ceil(log2(n)));
        int max_size = 2*(int)pow(2, x)-1;
        int *st= new int[max_size];

        constructSTUtil(arr, 0, n-1, st, 0);
        return st;
}
//changes
int maxVal(int x, int y)
{
        return (x > y)? x: y;
}

int RMQUtil_m(int *st, int ss, int se, int qs, int qe, int index)
{
        if (qs <= ss && qe >= se)
                return st[index];

        if (se < qs || ss > qe)
                return INT_MAX;

        int mid = getMid(ss, se);
        return maxVal(RMQUtil_m(st, ss, mid, qs, qe, 2*index+1),
                      RMQUtil_m(st, mid+1, se, qs, qe, 2*index+2));
}

int RMQ_m(int *st, int n, int qs, int qe)
{
        if (qs < 0 || qe > n-1 || qs > qe) {
                printf("Invalid Input");
                return -1;
        }

        return RMQUtil_m(st, 0, n-1, qs, qe, 0);
}
int constructSTUtil_m(int arr[], int ss, int se, int *st, int si)
{
        if (ss == se) {
                st[si] = arr[ss];
                return arr[ss];
        }

        int mid = getMid(ss, se);
        st[si] =  maxVal(constructSTUtil_m(arr, ss, mid, st, si*2+1),
                         constructSTUtil_m(arr, mid+1, se, st, si*2+2));
        return st[si];
}

int *constructST_m(int arr[], int n)
{

        int x = (int)(ceil(log2(n)));
        int max_size = 2*(int)pow(2, x)-1;
        int *st= new int[max_size];

        constructSTUtil_m(arr, 0, n-1, st, 0);
        return st;
}
//rmq ends

main()
{
        int N,i,Q,L,R,j;
        N=fastread();
        //scanf("%d",&N);
        int b[N];
        float C[N],maxm,minm;


        for(i=0; i<N; i++) {
                // scanf("%d",&b[i]);
                b[i]=fastread();
        }

        int *st = constructST(b, N);
        int *m_st=constructST_m(b,N);

        // scanf("%d",&Q);
        Q=fastread();

        for(j=0; j<Q; j++) {
                //scanf("%d",&L);
                //scanf("%d",&R);
                L=fastread();
                R=fastread();


                //call RMQ for fast processing
                minm= RMQ(st, N, L, R);

                for(i=0; i<L; i++) {
                        C[i]= (minm+b[i]);
                }
                for(i=R+1; i<N; i++) {
                        C[i]= (minm+b[i]);
                }

                for(i=L; i<=R; i++) {
                        C[i]= (float)(minm+b[i])/(float)(2);
                }

                maxm=C[0];
                for(i=1; i<N; i++) {
                        if(C[i]>maxm)
                                maxm=C[i];
                }
                printf("%.1f\n",maxm);
        }

        return 0;
}
