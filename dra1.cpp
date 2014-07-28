#include<cassert>
#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<climits>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;
int P[200100]; // longest prime number at index i

int limit= 100020; // generate prime number till 100020
int sqrtlimit= sqrt(limit);
bool sieve[100020];
int prime_before[100020];// stores prime number less than i

void  sieve_algo()
{
    int n,i;
    memset(sieve,false,sizeof(sieve)); // false means prime
    memset(prime_before,0,sizeof(prime_before));
    for (n=4;n<=limit;n=n+2)
    {
        sieve[n]=true; //making even number true, as they cant be prime
    }
    for(n=3;n<sqrtlimit;n=n+2)
    {
        if(!sieve[n])
        {
            for(int m=n*n;m<=limit;m=m+(2*n))
            {
                sieve[m]=true; // not prime
            }
        }
    }
    prime_before[0]=0;
    prime_before[1]=0;
    for(i=2;i<=limit;i++)
    {
        if(sieve[i]==false) //if prime
          {
             prime_before[i]= prime_before[i-1]+1;
          }
          else prime_before[i]= prime_before[i-1];
    }
    return;
}
// preprocess the string
string preprocess(string s)
{
  int l = s.size();
  int i;
  if(l==0)
    return "^$";
  string str1 = "^";
  for (i=0;i<l;i++)
    str1 += "#" + s.substr(i, 1);
  str1 += "#$";
  return str1;
}


void testing(int length_P, string str)
{
    int center, half_length,start,h=0;
    string substr;
    for(int i=1;i<=length_P;i++)
                {
                    if(P[i]>1)
                    {
                         if(P[i]%2==1) // for odd palindromes
                         {
                                center= (i/2-1);
                                half_length= P[i]/2;
                             while(half_length>=0)
                             {
                                 start= center- half_length;
                                 substr= str.substr(start, 2*half_length+1);
                                 if(substr.size()>1 && sieve[substr.size()]==false){h++;
                                 cout<<"h = "<<h<<" starto= "<<start<<" and endo= "<<(start+ 2*half_length+1)<<" = "<<substr<<" len = "<<substr.size()<<endl;}
                                 half_length--;
                             }
                         }
                         else // for even palindromes
                         {
                            center= (i/2);
                            half_length= P[i]/2;
                            while(half_length>0)
                            {
                                start= center- half_length;
                                substr= str.substr(start,2*half_length);
                                if(substr.size()>1 && sieve[substr.size()]==false){h++;
                                 cout<<"h = "<<h<<" starte= "<<start<<" and ende= "<<(start+ 2*half_length)<<" = "<<substr<<" len = "<<substr.size()<<endl;}
                                 half_length--;

                            }
                         }
                    }

                }
}
int manacher_algorithm(string s)
{
      string T = preprocess(s);
      int i;
      int n = T.length();
      int C = 0, R = 0;
      int start=0;
      //cout<<T<<endl;
      int st;
      for (i = 1; i < n-1; i++)
      {
            start=i;
            int i_dash = 2*C-i;
            P[i] = (R > i) ? min(R-i, P[i_dash]) : 0;
            while(T[i + 1 + P[i]] == T[i - 1 - P[i]])
              P[i]++;
            if (i + P[i] > R)
            {
              C = i;
              R = i + P[i];
            }
      }
      int total_pal=0,len;
      //cout<<endl;
      for(i=1;i<=n-2;i++)
      {
            // length of the longest palindrome centred at index i
            len =P[i];
            // testing

            if(len >=3 && len%2==1)// it is odd then do
            {
                total_pal+= (prime_before[len]-1); // number of primes less than len removing prime number 2
            }
            else if(len%2 ==0 && len>=2) // only 2 is a prime
            {
               total_pal++;
            }
      }
      //cout<<endl;
     //  testing(n-2,s);
       return total_pal;
}
int main()
{
          //freopen("C:\\Users\\cyber\\Desktop\\small_output1.txt", "w", stdout);
          //freopen("C:\\Users\\cyber\\Documents\\ccl.txt", "r", stdin);
    sieve_algo(); // precompute
    //testing();

    int test_cases,prime_palindromes,len;
    string str;
    scanf("%d",&test_cases);
    while(test_cases--)
    {
        cin>>str;
        len= str.size();
        assert(len>0 && len<100000);
        prime_palindromes= manacher_algorithm(str);
        printf("%d\n",prime_palindromes);
    }
   return 0;
}
