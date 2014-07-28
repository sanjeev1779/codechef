#include<stdio.h>
#include<math.h>
main()
{
    int test_cases,k,si,ci,A,i,P,T;
    float R;
    scanf("%d",&test_cases);
    for(k=0;k<test_cases;k++)
    {
        scanf("%d %f %d",&P,&R,&T);
        si=P*R*T/100;
        ci=P*pow((1+R/100),T)-P;
        printf("%d %d\n",si,ci);
    }

return 0;
}
