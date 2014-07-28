// after change

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
#define mp make_pair
using namespace std;
main()
{
    LL test_cases,N,N_org,k,final_ans=0, p_x_size, p_y_size, i ,doit;
    LL max_val_x_y,x,y,max_val_x_x,max_val_y_x,max_val_y_y,cnt,distinct_y,distinct_x;
    LL x_attack, y_attack;
    LL  maxm_x, maxm_y, k_X_x, k_Y_y, k_Y_x,k_X_y,updated_ans;

    //S(test_cases);
    cin>>test_cases;
    LL arr[1005][2];
    while(test_cases--)
    {

        final_ans=0;
        //S(N);
        cin>>N;
        N_org=N;
        pair<LL, LL>p_x[N+2];
        pair<LL,LL>p_y[N+2];
        for(i=0;i<N;i++)
        {
            scanf("%lld %lld",&x,&y);
            arr[i][0]=x;
            arr[i][1]=y;
            p_x[i]= mp(x,y);
            p_y[i]= mp(y,x);
        }
        p_x_size= N;
        p_y_size=N;
        int first_time=0;
        // main code starts here
        while(N>0)
        {
            x_attack=0;
            y_attack=0;
               //cout<<"p_x_size: "<< p_x_size<<"p_y_size:"<<p_y_size<<endl;
                sort(p_x, p_x+ p_x_size);
                sort(p_y, p_y+ p_y_size);

                maxm_x = -10;
                cnt=1;
                max_val_x_x= p_x[0].first;
                max_val_x_y= p_x[0].second;

                // for x cord
                int f=0;
                distinct_x=0;
                distinct_y=0;
                for(i=0;i<p_x_size-1;i++)
                {
                    if(p_x[i].first == p_x[i+1].first)
                    {
                        cnt++;
                    }
                    else f=1;

                    if(f==1)
                    {
                        distinct_x++;
                        if(cnt>=maxm_x)
                        {
                            maxm_x=cnt;
                             max_val_x_x= p_x[i].first;
                            max_val_x_y= p_x[i].second;
                        }

                        cnt=1;
                        f=0;
                    }
                }
                distinct_x++;
                // last index is not checked in above
                  if(cnt>=maxm_x)
                        {

                            maxm_x=cnt;
                            max_val_x_x= p_x[i].first;
                            max_val_x_y= p_x[i].second;
                        }



                // for y cord
               maxm_y = -10;
                cnt=1;
                max_val_y_y= p_y[0].first;
                max_val_y_x= p_y[0].second;

                // for y cord
                f=0;
                distinct_y=0;
                for(i=0;i<p_y_size-1;i++)
                {
                    if(p_y[i].first== p_y[i+1].first)
                    {
                        cnt++;
                    }
                    else f=1;

                    if(f==1)
                    {
                        distinct_y++;
                        if(cnt>=maxm_y)
                        {
                            maxm_y=cnt;
                             max_val_y_y= p_y[i].first;
                            max_val_y_x= p_y[i].second;
                        }

                        cnt=1;
                        f=0;
                    }
                }
                distinct_y++;
                // last index is not checked in above
                  if(cnt>=maxm_y)
                        {
                            maxm_y=cnt;
                             max_val_y_y= p_y[i].first;
                            max_val_y_x= p_y[i].second;
                        }
                        if(first_time==0)
                        {
                            first_time=1;
                            updated_ans= min( distinct_x, distinct_y);
                        }

               // cout<<"max_x="<< maxm_x<<" ";
               // cout<<"max_y="<< maxm_y<<" ";
                //cout<<"distinct x:"<<distinct_x<<" and "<<"distinct_y= "<<distinct_y<<endl;
                //cout<<"max_val_y_x "<<max_val_y_x<<" "<<"max_val_y_y: "<<max_val_y_y<<endl;
                //cout<<"max_val_x_x "<<max_val_x_x<<" "<<"max_val_x_y: "<<max_val_x_y<<endl;
                 // time to compare maxm y and maxm x

                 // here we will delete the rows corresponding to the maxm freq
                doit=0;

                 if(maxm_x> maxm_y && doit==0)
                 {
                  //   cout<<"row is selected 1st case\n";
                     doit=1; // it is done , so next is cancelled
                     N= N- maxm_x;
                     final_ans++;
                     x_attack=1;
                     //delete the x coor
                    // delete_x= max_val_x_X;
                    // update rows
                     k_X_x=0;
                     for(i=0;i<N_org;i++)
                     {

                         if(arr[i][0] !=  max_val_x_x)
                         {
                             p_x[k_X_x]= mp(arr[i][0], arr[i][1]);
                             k_X_x++;
                         }
                     }
                        p_x_size= k_X_x;

                        // update cols
                         k_X_y=0;
                     for(i=0;i<N_org;i++)
                     {

                        if(arr[i][1]!= max_val_x_y)
                        {
                            p_y[k_X_y]= mp(arr[i][1], arr[i][0]);
                            k_X_y++;
                        }
                     }
                     p_y_size= k_X_y;
                 }

                 // cols to be deleted
                 else if( maxm_x< maxm_y && doit==0) //undone
                 {
                     doit=1;
                    // cout<<"col is selected 1st case\n";
                     N= N- maxm_y;
                     final_ans++;
                     y_attack=1;

                    // update cols
                     k_Y_y=0;
                     for(i=0;i<N_org;i++)
                     {
                         if(arr[i][1]!= max_val_y_y)
                         {
                             p_y[k_Y_y]= mp(arr[i][1], arr[i][0]);
                             k_Y_y++;
                         }
                     }

                     p_y_size= k_Y_y;

                     // update rows

                     k_Y_x=0;
                     for(i=0;i<N_org;i++)
                     {
                         if(arr[i][0]!= max_val_y_x)
                         {
                             p_x[k_Y_x]= mp(arr[i][0], arr[i][1]);
                         }
                         k_Y_x++;
                     }
                     p_x_size= k_Y_x;
                 }// update end

                 // if both are equal
                 else if( maxm_x== maxm_y && doit==0) //undone
                 {
                     doit=1;

                    if(distinct_x >= distinct_y)
                    {
                     //   cout<<"row is selected 2nd case\n";
                                                doit=1; // it is done , so next is cancelled
                                 N= N- maxm_x;
                                 final_ans++;
                                 x_attack=1;
                                 //delete the x coor
                                // delete_x= max_val_x_X;
                                // update rows
                                 k_X_x=0;
                                 for(i=0;i<N_org;i++)
                                 {

                                     if(arr[i][0] !=  max_val_x_x)
                                     {
                                         p_x[k_X_x]= mp(arr[i][0], arr[i][1]);
                                         k_X_x++;
                                     }
                                 }
                                    p_x_size= k_X_x;

                                    // update cols
                                     k_X_y=0;
                                 for(i=0;i<N_org;i++)
                                 {

                                    if(arr[i][1]!= max_val_x_y)
                                    {
                                        p_y[k_X_y]= mp(arr[i][1], arr[i][0]);
                                        k_X_y++;
                                    }
                                 }
                                 p_y_size= k_X_y;
                    }


                    else  // for cols delete
                    {
                       // cout<<"col is selected 2nd case\n";
                             N= N- maxm_y;
                             final_ans++;
                             y_attack=1;

                            // update cols
                             k_Y_y=0;
                             for(i=0;i<N_org;i++)
                             {
                                 if(arr[i][1]!= max_val_y_y)
                                 {
                                     p_y[k_Y_y]= mp(arr[i][1], arr[i][0]);
                                     k_Y_y++;
                                 }
                             }

                             p_y_size= k_Y_y;

                             // update rows

                             k_Y_x=0;
                             for(i=0;i<N_org;i++)
                             {
                                 if(arr[i][0]!= max_val_y_x)
                                 {
                                     p_x[k_Y_x]= mp(arr[i][0], arr[i][1]);
                                 }
                                 k_Y_x++;
                             }
                             p_x_size= k_Y_x;
                    }


                 } // equal condtion ends


        }// end while N>0
        if(final_ans< updated_ans)
            printf("%lld\n",final_ans);
        else
            printf("%lld\n",updated_ans);



    } // end test_ cases


return 0;
}
