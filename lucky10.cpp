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
using namespace std;
main()
{
    int test_cases,l,minm1,i;
    S(test_cases);
   // string A,B;
    char A[20002],B[20002];

    int freq1[11],freq2[11];

    while(test_cases--)
    {
        //string C;
        memset(freq1,0,sizeof(freq1));
        memset(freq2,0,sizeof(freq2));
        scanf("%s %s",A,B);

        l= strlen(A);
        for(i=0;i<l;i++)
        {
           freq1[A[i]-'0']++;
           freq2[B[i]-'0']++;
        }

        freq1[0]= freq1[0]+freq1[1]+freq1[2]+freq1[3];
        freq2[0]= freq2[0]+freq2[1]+freq2[2]+freq2[3];

        freq1[5]= freq1[5]+freq1[6];
        freq2[5]= freq2[5]+freq2[6];

        freq1[8]= freq1[8]+freq1[9];
        freq2[8]= freq2[8]+freq2[9];


//1st
        if(freq1[7]>0 && freq2[5]>0) // replaced the 5s of B by 7s of A
        {
            minm1= min(freq1[7],freq2[5]);
            for(i=0;i<minm1;i++)
               // C=C+ "7";
               printf("7");
            freq1[7]-=minm1;
            freq2[5]-=minm1;
        }
// 2nd
        if(freq1[5]>0 && freq2[7]>0)  // replaced the 5s of A by 7s of B
        {
            minm1= min( freq1[5],freq2[7]);
            for(i=0;i<minm1;i++)
               // C=C+"7";
               printf("7");
            freq1[5]-=minm1;
            freq2[7]-=minm1;
        }

// 3rd
        if(freq1[7]>0 && freq2[0]>0)
        {
            minm1= min( freq1[7],freq2[0]);
            for(i=0;i<minm1;i++)
               // C=C+"7";
               printf("7");
            freq1[7]-=minm1;
            freq2[0]-=minm1;
        }

 // 4th

        if(freq1[0]>0 && freq2[7]>0)  // replaced the 5s of A by 7s of B
        {
            minm1= min( freq1[0],freq2[7]);
            for(i=0;i<minm1;i++)
                //C=C+"7";
                printf("7");
            freq1[0]-=minm1;
            freq2[7]-=minm1;
        }

// 5th

        if(freq1[7]>0 && freq2[4]>0)  // replaced the 5s of A by 7s of B
        {
            minm1= min( freq1[7],freq2[4]);
            for(i=0;i<minm1;i++)
                //C=C+"7";
                printf("7");
            freq1[7]-=minm1;
            freq2[4]-=minm1;
        }

 // 6th
        if(freq1[4]>0 && freq2[7]>0)  // replaced the 5s of A by 7s of B
        {
            minm1= min( freq1[4],freq2[7]);
            for(i=0;i<minm1;i++)
               // C=C+"7";
               printf("7");
            freq1[4]-=minm1;
            freq2[7]-=minm1;
        }

  // 7th
            if(freq1[7]>0 && freq2[7]>0)  // replaced the 5s of A by 7s of B
        {
            minm1= min( freq1[7],freq2[7]);
            for(i=0;i<minm1;i++)
              //  C=C+"7";
              printf("7");
            freq1[7]-=minm1;
            freq2[7]-=minm1;
        }

// 8th
        if(freq1[4]>0 && freq2[0]>0)  // replaced the 5s of A by 7s of B
        {
            minm1= min( freq1[4],freq2[0]);
            for(i=0;i<minm1;i++)
               // C=C+"4";
               printf("4");
            freq1[4]-=minm1;
            freq2[0]-=minm1;
        }
 // 9th
        if(freq1[0]>0 && freq2[4]>0)  // replaced the 5s of A by 7s of B
        {
            minm1= min( freq1[0],freq2[4]);
            for(i=0;i<minm1;i++)
                //C=C+"4";
                printf("4");
            freq1[0]-=minm1;
            freq2[4]-=minm1;
        }

// 10th
        if(freq1[4]>0 && freq2[4]>0)  // replaced the 5s of A by 7s of B
        {
            minm1= min( freq1[4],freq2[4]);
            for(i=0;i<minm1;i++)
               // C=C+"4";
               printf("4");
            freq1[4]-=minm1;
            freq2[4]-=minm1;
        }

        printf("\n");
    }


return 0;
}
