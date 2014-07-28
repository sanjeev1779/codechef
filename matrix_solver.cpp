#include <stdio.h>
#include <process.h>
float **a, *b, *x;
int N;



void readmatrix(){
   int i=0,j=0;
   //read matrixes a and b from input file
   for(i=0; i<N; i++){
       for(j=0; j<N; j++){
	   scanf("%d", &a[i][j]);
       }
       scanf("%f", &b[i]);
   }
}

void printmatrix(){
   //print matrix "a"
   int i=0,j=0;
   printf("\n");
   for(i=0; i<N; i++){
       for(j=0; j<N; j++){
	   printf(" %d ", a[i][j]);
       }
       printf("d\n", b[i]);
   }
}

void testsolve(){
   //test that ax=b
   int i=0,j=0;
   printf("\n");
   for(i=0; i<N; i++){
       float s = 0;
       for(j=0; j<N; j++){
	   s += a[i][j]*x[j];
       }
       printf("%f\t%f\n", s, b[i]);
   }
}
void printresult(){
   int i=0;
   printf("\n");
   printf("Result\n");
   for(i=0; i<N; i++){
       printf("X%d = %f\n", i, x[i]);
   }
}
void diagonal(){
   int i, j, k;
   float temp=0;
   for(i=0; i<N; i++){
       if(a[i][i]==0){
	   for(j=0; j<N; j++){
	       if(j==i) continue;
	       if(a[j][i] !=0 && a[i][j]!=0){
		   for(k=0; k<N; k++){
		       temp = a[j][k];
		       a[j][k] = a[i][k];
		       a[i][k] = temp;
		   }
		   temp = b[j];
		   b[j] = b[i];
		   b[i] = temp;
		   break;
	       }
	   }
       }
   }
}
void cls(){
   for(int i=0; i<25; i++) printf("\n");
}
int main(){
   int i=0,j=0, k=0;
   readmatrix();
   //check if there are 0 on main diagonal and exchange rows in that case
   diagonal();
   printmatrix();
   //process rows
   for(k=0; k<N; k++){
       for(i=k+1; i<N; i++){
	   if(a[k][k]==0){
	       printf("\nSolution is not exist.\n");
	       break;
	   }
	   float M = a[i][k] / a[k][k];
	   for(j=k; j<N; j++){
	       a[i][j] -= M * a[k][j];
	   }
	   b[i] -= M*b[k];
       }
   }
   printmatrix();
   for(i=N-1; i>=0; i--){
       float s = 0;
       for(j = i; j<N; j++){
	   s = s+a[i][j]*x[j];
       }
       x[i] = (b[i] - s) / a[i][i];
   }
   readmatrix();
   printmatrix();
   testsolve();
   printresult();
}
