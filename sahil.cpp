#include<stdio.h>
int main()
{
    int n,j,i,minIndex=1,maxIndex=1;
    long area =0,max=0,min=0;
    scanf("%d",&n);

    for(j = 1;j<=n;j++)
    {
        int points[6];
        for(i =0;i<6;i++)
        {
            scanf("%d",&points[i]);
        }
      area = (points[0]*(points[3]-points[5])+ points[2]*(points[5]-points[1])+points[4]*(points[1]-points[3]));
          if(area<0)
        {
            area = (-1)*area;
        }
            if(j==1)
      {
          min = area;
          max = area;
      }
        if(area>=max)
        {
            max = area;
            maxIndex = j;

        }
         if(area<=min)
        {

            min = area;
            minIndex= j;
        }
    }
    printf("%d %d\n",minIndex,maxIndex);
    return 0;
}
