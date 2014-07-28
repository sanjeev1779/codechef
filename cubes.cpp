#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<climits>
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
int main()
{
    int t,n,i,j,k,temp;
    int cube[42][42][42];
    char sa[68921],sb[68921];
	int p,csize,counter,idx=0;
    //freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
	S(t)
	while(t--)
	{
        S(n) S(p)
        idx=0;
		scanf("%s %s",sa,sb);
		memset(cube,0,sizeof(cube));


        for( i=1;i<=n;i++)
            for( j=1;j<=n;j++)
                for(k=1;k<=n;k++)
                {
                    if(sa[(i-1)*n*n+(j-1)*n+k-1]==sb[(i-1)*n*n+(j-1)*n+k-1])
                    {
                            cube[i][j][k]=cube[i-1][j][k]+cube[i][j-1][k]+cube[i][j][k-1]-cube[i][j-1][k-1]-cube[i-1][j][k-1]-cube[i-1][j-1][k]+cube[i-1][j-1][k-1]+1;
                    }
                    else
                        cube[i][j][k]=cube[i-1][j][k]+cube[i][j-1][k]+cube[i][j][k-1]-cube[i][j-1][k-1]-cube[i-1][j][k-1]-cube[i-1][j-1][k]+cube[i-1][j-1][k-1];

                }

		for(csize=n;csize>0;csize--)
		{
			counter=0;
			for(i=n;i-csize>=0;i--)
			{
				for(j=n;j-csize>=0;j--)
				{
					for(k=n;k-csize>=0;k--)
					{
     					 temp=cube[i][j][k]+cube[i][j-csize][k-csize]+cube[i-csize][j][k-csize]+cube[i-csize][j-csize][k]-cube[i-csize][j][k]-cube[i][j-csize][k]-cube[i][j][k-csize]-cube[i-csize][j-csize][k-csize];

						if((temp*100)>=p*(csize*csize*csize))
						   {
						       counter++;
						   }
      				}
				}
			}
			if(counter>0)
			 {
			   //  cout<<csize<<endl;
			       break;
			 }
		}


		if(csize==0)
		  printf("-1\n");
		else
		   printf("%d %d\n",csize,counter);
	}
return 0;
}
