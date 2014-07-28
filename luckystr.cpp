#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
main()
{
    int k,n,i,lenstr,lensubstr,j;
    std:: string substr[52];
    std:: string str[55];
    std:: string str1;
    string substr_copy,str_copy;
    cin>>k>>n;
    for(i=0;i<k;i++)
    {
        cin>>substr[i];
        substr_copy[i]=substr[i];
    }

    for(i=0;i<n;i++)
    {
        cin>>str[i];
        str_copy[i]=str[i];
    }

    for(i=0;i<n;i++)
    {
        lenstr=strlen_copy(str[i]);
        if(lenstr>46)
        {
                cout<<"Good\n";
        }
        else
        {
            int p=1;
            for(j=0;j<k;j++)
            {
                lensubstr= strlen_copy(substr[j]);

                int x=0;
                if(lensubstr<=lenstr)
                {
                    std:: str1= str.substr(x,x+lensubstr);
                    if(strcmp(str1,substr[j])==0)
                    {
                        p=0;
                        cout<<"Good\n";
                        break;
                    }
                    x++;

                }
            }
            if(p==1)
            {
                cout<<"Bad\n";
            }
        }
    }

return 0;
}
