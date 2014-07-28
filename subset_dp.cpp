// Solves subset sum using dynamic programming

#include <stdio.h>
#include <stdlib.h>

// S[1] . . . S[n] are the input values
// A[k] will store the smallest subscript value j s.t. there is some
//      subset of S[1] . . . S[j-1], along with S[j], that sums to k
int *S,*A,C,n;

main()
{
int i,j,k,sum;

printf("Enter C and n\n");
scanf("%d %d",&C,&n);

S=(int*) malloc((n+1)*sizeof(int));
A=(int*) malloc((C+1)*sizeof(int));
if (!S || !A)
{
  printf("malloc failed %d\n",__LINE__);
  exit(0);
}

printf("Enter set of %d positive numbers\n",n);
S[0]=0;
for (i=1;i<=n;i++)
  scanf("%d",&S[i]);

for (i=0;i<=C;i++)
  A[i]=(-1);  // initialize to "impossible"

A[0]=0;  // This is a cute way to force the initialization in Notes 18.
for (i=0;i<C;i++)
  // Derive other cases from optimal way to get A[i]
  if (A[i]!=(-1))
    // The S[] values increase the sum in increasing subscript order.
    for (j=A[i]+1;j<=n;j++)
    {
      k=i+S[j];
      if (k>C)
        continue;
      // See if A[k] can be improved
      if (A[k]==(-1) || A[k]>j)
      {
        printf("Changed A[%d] to %d\n",k,j);
        A[k]=j;
      }
    }

if (C<=50)
{
  printf(" i     S[i]\n");
  printf("--- ----------\n");
  for (i=1;i<=n;i++)
    printf("%3d     %4d\n",i,S[i]);
  printf(" i     A[i]\n");
  printf("--- ----------\n");
  for (i=1;i<=C;i++)
  {
    printf("%3d ",i);
    if (A[i]==(-1))
      printf("IMPOSSIBLE\n");
    else
      printf("%5d (%d)\n",A[i],S[A[i]]);
  }
}

if (A[C]==(-1))
  printf("no solution\n");
else
{
  // traceback to get subset
  printf("Solution is:\n");
  sum=C;
  while (sum>0)
  {
    printf("S[%d]=%d\n",A[sum],S[A[sum]]);
    sum-=S[A[sum]];  // Remove last S[] value included in sum.
  }
}
free(S);
free(A);
}
