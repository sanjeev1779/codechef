#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <math.h>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
inline void fastInput(long int &x) {
    register int c = getchar();
    x = 0;
    int neg = 0;
    for(; ((c<48 || c>57) && c != '-'); c = getchar());
    if(c=='-') {
        neg = 1;
        c = getchar();
    }
    for(; c>47 && c<58 ; c = getchar()) {
        x = (x<<1) + (x<<3) + c - 48;
    }
    if(neg)
        x = -x;
}
int main()
{
    long int t;
    fastInput(t);
    while(t--)
    {
        long int c,d;
        fastInput(c);
        fastInput(d);
        long long ans = (c*d)-c-d;
        cout << ans << endl;
    }
    return 0;
}
