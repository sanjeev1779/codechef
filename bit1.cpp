#include<iostream>
#include <cstdio>
#define LSOne(S) (S & (-S))
using namespace std;
class BIT {

    public:    int* ft, size;

public:

        // initialize a BIT of n elements to zero
        BIT(int n) {
                size = n;
                ft = new int[n+1];
        }

        ~BIT()  {
                delete [] ft;
        }

        // returns sum of the range [1...b]
        int sum(int b) {
                int sum = 0;
                //for (; b>0; b -= LSOne(b)) sum += ft[b];
                while(b>0)
                {
                    sum+= ft[b];
                    b-= (b&-b);
                }
                return sum;
        }

        // returns sum of the range [a...b]
        int sum(int a, int b) {
                return sum(b) - (a == 1 ? 0 : sum(a - 1));
        }

        // update value of the k-th element by v (v can be +ve/inc or -ve/dec)
        // i.e., increment or decrement kth element by a value v
        void update(int k, int v) {
                for (; k <= size; k += LSOne(k)) ft[k] += v;
        }

    // divide each original frequency by c
        void scaleDown(int c){
        for (int i=1 ; i<=size ; i++) ft[i] /= c;
    }

    // multiply each original frequency by c
    void scaleUp(int c){
        for (int i=1 ; i<=size ; i++) ft[i] *= c;
    }
};

int main()  {
    int i;
    BIT b(10);
   // printf("%d\n", b.sum(10));


          cout<<"hi\n";
          b.update(1, 10);

           cout<<"hi\n";
           b.update(2, 20);
           b.update(3, 30);
           b.update(4, 40);
           b.update(5, 50);
           b.update(6, 60);
           b.update(8, 80);
        cout<<b.ft[2]<<endl;
    printf("%d %d %d %d\n", b.sum(1), b.sum(2), b.sum(5), b.sum(1, 2));
    b.update(1, -10);
    printf("%d %d %d %d\n", b.sum(1), b.sum(2), b.sum(5), b.sum(6, 10));
    printf("%d %d\n",b.sum(7),b.sum(8));
    b.scaleUp(2);
    printf("%d %d %d %d\n", b.sum(1), b.sum(2), b.sum(5), b.sum(6, 10));

    b.scaleDown(2);
    printf("%d %d %d %d\n", b.sum(1), b.sum(2), b.sum(5), b.sum(6, 10));

    return 0;
}
