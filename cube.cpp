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
main()
{
    double x;
    int test_cases,i,j,flag,si,least_mat,matched,min_size,cnt,l,N,P, not_matched, min_si;
    S(test_cases);
    string str1,str2;

    while(test_cases--)
    {
        scanf("%d %d",&N,&P);
        cin>>str1;
        cin>>str2;
        l=str1.size();
        int mismat[l+10];
        mismat[0]=0;
        for(i=1;i<=l;i++)
        {
            if(str1[i-1]!=str2[i-1])
                mismat[i]= mismat[i-1]+1;
            else
                mismat[i]=mismat[i-1];
        }
        flag=0;
        //starting from maximum value of the size to 1
        for(i=N;i>=1;i--) // size of cube
        {
            si= i*i*i; // vol of the cube
            x= ( (P*1.0)*(si*1.0)*1.0)/ (100.0);
            least_mat= ceil(x);
            for(j=1;j<=l-si+1;j++)
            {
                    not_matched= mismat[j+si-1]-mismat[j-1];
                    //prob_not_matched= (not_matched*100.0)/(si*1.0);
                    matched= si- not_matched;

                    if(matched>=least_mat)
                    {
                        flag=1;
                        min_size= i;
                        break;
                    }
            }
            if(flag==1)
                break;
        }
        if(flag==1)
        {
            cnt=0;
            //found largest cube of size min_size if flag is 1 , else return -1
            min_si= (min_size)*(min_size)*(min_size);
            least_mat= ceil( (P*min_si*1.0)/ 100.0);
            for(j=1;j<=l-min_si+1;j++)
            {
                not_matched= mismat[j+min_si-1] - mismat[j-1];
                matched= min_si- not_matched;
                if(matched>=least_mat)
                {
                    cnt++;
                }
            }
            printf("%d %d\n",min_size,cnt);
        }
        else
            printf("-1\n");

    }

return 0;
}
