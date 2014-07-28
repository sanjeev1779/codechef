#include <cstdio>
#include <cstring>
#include <algorithm>
#define XTREME true
using namespace std;

int N,M,K;
bool Used[105][105];
char Input[2200];int br;
char Output[90005];int bro;


inline void getint(int &x) {
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





inline void ucitaj_mapu_xtreme(){
    int x,y;
    getint(N);
    getint(M);
    getint(K);
    while (K--){
        getint(x);
        getint(y);
        Used[x][y] = true;
    }
}

short int Z[1005][1005];

inline void racunaj_z(){
    int i,j;
    for (i=1; i<=N; i++){
        for (j=1; j<=M; j++){
            Z[i][j] = Z[i-1][j] + (Used[i][j]);
            //printf("> Z[%d][%d] = %d\n",i,j,Z[i][j]);
        }
    }
}

int Sol[1005][1005];

inline void racunajsol(){
    int xl,xr,y,k,l;
    for (xl=1; xl<=N; xl++){
        for (xr=xl; xr<=N; xr++){
            k=0;
            l=0;
            for (y=1; y<=M; y++){
                if (Z[xr][y]-Z[xl-1][y] == 0) k++; else k=0;
                l = max(l,k);
            }
            //printf(">> %d %d %d\n",xl,xr,l);
            Sol[xl][xr] = l*(xr-xl+1);
        }
    }
    for (l=1; l<N; l++){
        for (xr=l+1; xr<=N; xr++){
            Sol[xr-l][xr] = max(max(Sol[xr-l+1][xr],Sol[xr-l][xr-1]),Sol[xr-l][xr]);
        }
    }
}

inline void resiupite_ord(){
    int xl,xr,q;
    scanf("%d",&q);
    while (q--){
        scanf("%d%d",&xl,&xr);
        printf("%d\n",Sol[xl][xr]);
    }
}

int main(){
        ucitaj_mapu_xtreme();
        racunaj_z();
        racunajsol();
        resiupite_ord();
    return 0;
}
