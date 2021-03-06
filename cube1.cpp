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
    int least_mat,vol;
    int test_cases,N,P,i,j,k,flag=0,si,matched=0,min_size=0,cnt=0,idx;
    S(test_cases);
    string str1,str2;
    int A[42][42][42], B[42][42][42], matched_AB[42][42][42];
    while(test_cases--)
    {
        memset(matched_AB,0,sizeof(matched_AB));
        S(N);S(P);
        idx=0;
        cin>>str1>>str2;
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=N;j++)
            {
                for(k=1;k<=N;k++)
                {
                    A[i][j][k]= str1[idx]-'a';
                    B[i][j][k]= str2[idx]-'a';
                    idx++;
                }
            }
        } // read the string in the cube 3D format


   /*  for(i=1;i<=N;i++)
        {
            for(j=1;j<=N;j++)
            {
                for(k=1;k<=N;k++)
                {
                    printf("%d ",A[i][j][k]);
                    idx++;
                }
            }
            cout<<endl;
        } // read the string in the cube 3D format

        for(i=1;i<=N;i++)
        {
            for(j=1;j<=N;j++)
            {
                for(k=1;k<=N;k++)
                {
                    printf("%d ",B[i][j][k]);
                    idx++;
                }
            }
            cout<<endl;
        } // read the string in the cube 3D format
*/

        // finding the matched string in each section of the cube
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=N;j++)
            {
                for(k=1;k<=N;k++)
                {
                    matched_AB[i][j][k]= matched_AB[i][j-1][k]+ matched_AB[i][j][k-1] - matched_AB[i][j-1][k-1] +  ( A[i][j][k]== B[i][j][k] ? 1 :0);
                }
            }
        }
        // finding matched ended

        // find the largest cube of length S, start from length= N to 1
        flag=0; // not found
        for(si=N;si>=1;si--)
        {
            vol= si*si*si;

            x= ( (P*1.0)*(vol*1.0)*1.0)/ (100.0);
            least_mat= ceil(x);
          //  cout<<"least matched= "<<least_mat<<endl;
            for(i=1;i<=N-si+1;i++)
            {

                for(j=1;j<=N-si+1;j++)
                {
                    for(k=1;k<=N-si+1;k++)
                    {
                        matched=0;
                        for(idx=i;idx<=i+si-1;idx++)
                        {
                            // dis= dp[x1-1][y1-1][i]+ dp[x2][y2][i] - dp[x1-1][y2][i] - dp[x2][y1-1][i];
                            matched+= matched_AB[idx][j-1][k-1] + matched_AB[idx][j+si-1][k+si-1] - matched_AB[idx][j-1][k+si-1]- matched_AB[idx][j+si-1][k-1];
            //                cout<<"idx "<<idx<<" and matched= "<<matched<<endl;
                        }
              //          cout<<"characters matched = "<<matched<<endl;
                        if(matched>= least_mat)
                        {
                //            cout<<"si = "<<si<<endl;
                            min_size= si;
                            flag=1;
                            break;
                        }
                        if(flag)
                            break;

                    }
                    if(flag)
                        break;
                }
                if(flag)
                    break;

            }
            if(flag)
                break;
        }//end of the loop for finding the maximum length
        // find the number of such sub cubes of length min_size
        cnt=0;
      //  cout<<"min_szie= "<<min_size<<endl;
        if(flag==1) // found
        {
            vol= min_size*min_size*min_size;
            x= ( (P*1.0)*(vol*1.0)*1.0)/ (100.0);
            least_mat= ceil(x);
        //    cout<<"least_ match= "<<least_mat<<endl;
            // search for minimum matched sub cubes

            for(i=1;i<=N-min_size+1;i++)
            {
                for(j=1;j<=N-min_size+1;j++)
                {
                    for(k=1;k<=N-min_size+1;k++)
                    {
                        matched=0;
                            for(idx=i;idx<=i+min_size-1;idx++)
                            {
                                // dis= dp[x1-1][y1-1][i]+ dp[x2][y2][i] - dp[x1-1][y2][i] - dp[x2][y1-1][i];
                                matched+= matched_AB[idx][j-1][k-1] + matched_AB[idx][j+min_size-1][k+min_size-1] - matched_AB[idx][j-1][k+min_size-1]- matched_AB[idx][j+min_size-1][k-1];

                            }
                            if(matched>=least_mat)
                               {
                                 //  printf("found\n");
                                   cnt++;
                               }
                    }
                }
            }
            printf("%d %d\n",min_size,cnt);
        }
        else
            printf("-1\n");

    }


return 0;
}
