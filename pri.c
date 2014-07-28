#include<stdio.h>
main(void )
{
    char c;
    int n,i=2,a=0;
    scanf("%d",&n);
    for(;i*i<=n;i++)
    {
        if(n%i==0)
            a=1;
    }
    if(!a && n!=1)
        printf("YES");
    else{
    /*f = fopen(__FILE__,"r");
    while(c!=EOF)
    {
         c= getc(f);
         putchar(c);
    }*/
    char *s="#include <stdio.h>\n\nmain (void)\n{\n";
  printf(s);  printf("%s\";\n",s);
}
//fclose(f);
//return 0;
}
