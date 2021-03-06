
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#define FOR(c, m) for(int c=0;c<(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)


#define MAX_N 100010
#define MOD 1000000007

long long int a[MAX_N];
long long int steps[MAX_N];


char c = 0;
long long getInt() {
    long long int r = 0;
    while (!(c >= '0' && c <= '9')) c = getc_unlocked(stdin);
    while (c >= '0' && c <= '9') {
        r = r * 10 + (c - '0');
        c = getc_unlocked(stdin);
    }
    return r;
}

int main(void) {
    int t;
    scanf("%d",&t);
    while(t--){
    int n = getInt();
    long long int m = getInt();
    long long int k = getInt();
    long long int stepsTotal = 0;

    FOR(i, n) a[i] = getInt();
    FOR(i, n) {
        steps[i] = (m - a[i]) / k + 1;
        stepsTotal += steps[i];
    }


    long long int res = 0;
    FOR(i, n) {
        if (((stepsTotal - steps[i]) & 1) == 1) {
            a[i] += k;
        }
        if (a[i] <= m) {
            long long currMax = (m - a[i]) / (2 * k) + 1;
            if (currMax > res) res = currMax;
        }
    }
    if ((stepsTotal & 1) == 0) res++;
    printf("%lld\n", res % MOD);
    }
}
