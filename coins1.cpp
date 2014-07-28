#include <iostream>
#include <string.h>
using namespace std;

const int MAX = 10000000;

long long a[MAX];

long long find(long long n){
        int i;
        long long x;

        if(n<=MAX){
                if(a[n] == -1){
                        for(i=1; i<=n; i++){
                                if(a[i] == -1){
                                        x = a[i/2]+a[i/3]+a[i/4];
                                        a[i] = (x>i)?x:i;
                                }
                        }
                }
                return a[n];
        }
        x = find(n/2)+find(n/3)+find(n/4);
        return (x>n?x:n);
}

int main(){
        long long n;
        memset(a, -1, (MAX+1)*sizeof(long long));
        a[0] = 0;
        while(cin>>n){
                cout<<find(n)<<endl;
        }

        return 0;
}
