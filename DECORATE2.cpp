#include <iomanip>
#include <cstdlib>
#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
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


const int base = 1000000000;
const int base_digits = 9;
// big integer class
struct bigint {
    vector<int> a;
    int sign;

    bigint() :
        sign(1) {
    }

    bigint(long long v) {
        *this = v;
    }

    bigint(const string &s) {
        read(s);
    }

    void operator=(const bigint &v) {
        sign = v.sign;
        a = v.a;
    }

    void operator=(long long v) {
        sign = 1;
        if (v < 0)
            sign = -1, v = -v;
        for (; v > 0; v = v / base)
            a.push_back(v % base);
    }

    bigint operator+(const bigint &v) const {
        if (sign == v.sign) {
            bigint res = v;

            for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) {
                if (i == (int) res.a.size())
                    res.a.push_back(0);
                res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
                carry = res.a[i] >= base;
                if (carry)
                    res.a[i] -= base;
            }
            return res;
        }
        return *this - (-v);
    }

    bigint operator-(const bigint &v) const {
        if (sign == v.sign) {
            if (abs() >= v.abs()) {
                bigint res = *this;
                for (int i = 0, carry = 0; i < (int) v.a.size() || carry; ++i) {
                    res.a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0);
                    carry = res.a[i] < 0;
                    if (carry)
                        res.a[i] += base;
                }
                res.trim();
                return res;
            }
            return -(v - *this);
        }
        return *this + (-v);
    }

    void operator*=(int v) {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
            if (i == (int) a.size())
                a.push_back(0);
            long long cur = a[i] * (long long) v + carry;
            carry = (int) (cur / base);
            a[i] = (int) (cur % base);
            //asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));
        }
        trim();
    }

    bigint operator*(int v) const {
        bigint res = *this;
        res *= v;
        return res;
    }

    friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
        int norm = base / (b1.a.back() + 1);
        bigint a = a1.abs() * norm;
        bigint b = b1.abs() * norm;
        bigint q, r;
        q.a.resize(a.a.size());

        for (int i = a.a.size() - 1; i >= 0; i--) {
            r *= base;
            r += a.a[i];
            int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
            int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
            int d = ((long long) base * s1 + s2) / b.a.back();
            r -= b * d;
            while (r < 0)
                r += b, --d;
            q.a[i] = d;
        }

        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        return make_pair(q, r / norm);
    }

    bigint operator/(const bigint &v) const {
        return divmod(*this, v).first;
    }

    bigint operator%(const bigint &v) const {
        return divmod(*this, v).second;
    }

    void operator/=(int v) {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = (int) a.size() - 1, rem = 0; i >= 0; --i) {
            long long cur = a[i] + rem * (long long) base;
            a[i] = (int) (cur / v);
            rem = (int) (cur % v);
        }
        trim();
    }

    bigint operator/(int v) const {
        bigint res = *this;
        res /= v;
        return res;
    }

    int operator%(int v) const {
        if (v < 0)
            v = -v;
        int m = 0;
        for (int i = a.size() - 1; i >= 0; --i)
            m = (a[i] + m * (long long) base) % v;
        return m * sign;
    }

    void operator+=(const bigint &v) {
        *this = *this + v;
    }
    void operator-=(const bigint &v) {
        *this = *this - v;
    }
    void operator*=(const bigint &v) {
        *this = *this * v;
    }
    void operator/=(const bigint &v) {
        *this = *this / v;
    }

    bool operator<(const bigint &v) const {
        if (sign != v.sign)
            return sign < v.sign;
        if (a.size() != v.a.size())
            return a.size() * sign < v.a.size() * v.sign;
        for (int i = a.size() - 1; i >= 0; i--)
            if (a[i] != v.a[i])
                return a[i] * sign < v.a[i] * sign;
        return false;
    }

    bool operator>(const bigint &v) const {
        return v < *this;
    }
    bool operator<=(const bigint &v) const {
        return !(v < *this);
    }
    bool operator>=(const bigint &v) const {
        return !(*this < v);
    }
    bool operator==(const bigint &v) const {
        return !(*this < v) && !(v < *this);
    }
    bool operator!=(const bigint &v) const {
        return *this < v || v < *this;
    }

    void trim() {
        while (!a.empty() && !a.back())
            a.pop_back();
        if (a.empty())
            sign = 1;
    }

    bool isZero() const {
        return a.empty() || (a.size() == 1 && !a[0]);
    }

    bigint operator-() const {
        bigint res = *this;
        res.sign = -sign;
        return res;
    }

    bigint abs() const {
        bigint res = *this;
        res.sign *= res.sign;
        return res;
    }

    long long longValue() const {
        long long res = 0;
        for (int i = a.size() - 1; i >= 0; i--)
            res = res * base + a[i];
        return res * sign;
    }

    friend bigint gcd(const bigint &a, const bigint &b) {
        return b.isZero() ? a : gcd(b, a % b);
    }
    friend bigint lcm(const bigint &a, const bigint &b) {
        return a / gcd(a, b) * b;
    }

    void read(const string &s) {
        sign = 1;
        a.clear();
        int pos = 0;
        while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-')
                sign = -sign;
            ++pos;
        }
        for (int i = s.size() - 1; i >= pos; i -= base_digits) {
            int x = 0;
            for (int j = max(pos, i - base_digits + 1); j <= i; j++)
                x = x * 10 + s[j] - '0';
            a.push_back(x);
        }
        trim();
    }

    friend istream& operator>>(istream &stream, bigint &v) {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }

    friend ostream& operator<<(ostream &stream, const bigint &v) {
        if (v.sign == -1)
            stream << '-';
        stream << (v.a.empty() ? 0 : v.a.back());
        for (int i = (int) v.a.size() - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('0') << v.a[i];
        return stream;
    }

    static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
        vector<long long> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < (int) p.size(); i++)
            p[i] = p[i - 1] * 10;
        vector<int> res;
        long long cur = 0;
        int cur_digits = 0;
        for (int i = 0; i < (int) a.size(); i++) {
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) {
                res.push_back(int(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int) cur);
        while (!res.empty() && !res.back())
            res.pop_back();
        return res;
    }

    typedef vector<long long> vll;

    static vll karatsubaMultiply(const vll &a, const vll &b) {
        int n = a.size();
        vll res(n + n);
        if (n <= 32) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }

        int k = n >> 1;
        vll a1(a.begin(), a.begin() + k);
        vll a2(a.begin() + k, a.end());
        vll b1(b.begin(), b.begin() + k);
        vll b2(b.begin() + k, b.end());

        vll a1b1 = karatsubaMultiply(a1, b1);
        vll a2b2 = karatsubaMultiply(a2, b2);

        for (int i = 0; i < k; i++)
            a2[i] += a1[i];
        for (int i = 0; i < k; i++)
            b2[i] += b1[i];

        vll r = karatsubaMultiply(a2, b2);
        for (int i = 0; i < (int) a1b1.size(); i++)
            r[i] -= a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            r[i] -= a2b2[i];

        for (int i = 0; i < (int) r.size(); i++)
            res[i + k] += r[i];
        for (int i = 0; i < (int) a1b1.size(); i++)
            res[i] += a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            res[i + n] += a2b2[i];
        return res;
    }

    bigint operator*(const bigint &v) const {
        vector<int> a6 = convert_base(this->a, base_digits, 6);
        vector<int> b6 = convert_base(v.a, base_digits, 6);
        vll a(a6.begin(), a6.end());
        vll b(b6.begin(), b6.end());
        while (a.size() < b.size())
            a.push_back(0);
        while (b.size() < a.size())
            b.push_back(0);
        while (a.size() & (a.size() - 1))
            a.push_back(0), b.push_back(0);
        vll c = karatsubaMultiply(a, b);
        bigint res;
        res.sign = sign * v.sign;
        for (int i = 0, carry = 0; i < (int) c.size(); i++) {
            long long cur = c[i] + carry;
            res.a.push_back((int) (cur % 1000000));
            carry = (int) (cur / 1000000);
        }
        res.a = convert_base(res.a, 6, base_digits);
        res.trim();
        return res;
    }
};
// ########################     End of the big integer class ############################################
int phi(int num)
{
        int i,val=num;
        for(i=2;i*i<=num;i++)
        {
            if(num%i==0)
                val= val-val/i;
            while(num%i==0) num/=i;
        }
        if(num>1)
            val-=val/num;
        return val;
}
string T;
map<string,int>map_str;
int P[200040];
int length_P;


string pp(string s)
{
  int nl = s.size(),i;
  if (nl==0)
    return "^$";
  string str1 = "^";
  for (i=0;i<nl;i++)
    str1 += "#" + s.substr(i, 1);
  str1 += "#$";
  return str1;
}

void manacher_algorithm(string s)
{
      T = pp(s);
      int i;
      int n = T.length();
      int C = 0, R = 0;
      int start=0;
      //cout<<T<<endl;
      string str1;
      int st;
      for (i = 1; i < n-1; i++)
      {
            start=i;
            int i_dash = 2*C-i;

            P[i] = (R > i) ? min(R-i, P[i_dash]) : 0;

            while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
              P[i]++;

            if (i + P[i] > R)
            {
              C = i;
              R = i + P[i];
            }
       }
      length_P= n-2;
      //delete[] P;
}

main()
{
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
        LL cnt=0;

        //freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
        string str,substr;
        char spcl_char;
        int n,i,center,half_length,start,d,j;
        cin>>str;
        string str1=str;
        int cn;
        scanf("%d",&n);
        int ls= str.length();
        int freq[27]={0};
        for(i=0;i<ls;i++)
        {
            freq[str[i]-'a']++;
        }
        int k=0,end;
        int flag=0;
        LL a=0,x,y;
        for(i=0;i<26;i++)
        {
            if(freq[i]==ls)
            {
                a= ls;
                flag=1;
                break;
            }
        }

        // optimisation
      /*  map<char,int>freq_map[ls+1];
        for(i=0;i<ls;)
        {
            cn=1;
            for(j=i+1;j<ls;j++)
            {
                if(str[i]==str[j])
                {
                    cn++;
                }
                else break;
            }
            freq_map[k]= mp(str[i],cn);
            k++;
            i=i+cnt;
        }

        sort(freq_map.begin(),freq_map,end());
        if(k>60)
        {
            minm_freq_rep= freq_map[60].second;
        }
        else
            minm_freq_rep= freq_map[k].second;
            */
        spcl_char=33;
        string str_new="";
        string temp;
        for(i=0;i<ls;)
        {
            cn=1;
            start=i;
            for(j=i+1;j<ls;j++)
            {
                if(str[i]==str[j])
                {
                    cn++;
                }
                else break;
            }
            end=i+cn;
            if(cn>=2) //replace
            {
                str_new= str_new+ spcl_char;
                spcl_char++;
                // have to do
                temp="";
                for(j=0;j<cn;j++)
                {
                    temp+= str[start];
                     //checking for uniqueness of the palindrome
                                 if( map_str.find(temp)!=map_str.end())
                                 {
                                     //present;
                                     //do nothing;
                                 }
                                 else
                                 {
                                     map_str[temp]=1;
                                     cnt++;
                                 }
                }


                if(spcl_char>96)
                    break;
            }
            else
            {
                for(j=start; j<end ;j++)
                {
                    str_new= str_new+ str[j];
                }
            }
            i=i+cn;
        }
        // replacing the character with other symbol
        //end of optimization


        //manacher_algorithm algo

        y= spcl_char;
        cnt= cnt- (y-33);
      //  cout<<y<<endl;
        //cout<<" new string "<<str_new<<endl;
        //cout<<map_str.size()<<endl;
        //call manacher algorithm for finding the longest palindrom at each center
        if(flag==0)
        {
                manacher_algorithm(str_new);
                for(i=1;i<=length_P;i++)
                {
                    if(P[i]>0)
                    {
                         if(P[i]%2==1) // for odd palindromes
                         {
                             center= (i/2-1);
                                half_length= P[i]/2;
                             while(half_length>=0)
                             {
                                 start= center- half_length;
                                 substr= str_new.substr(start, 2*half_length+1);
                                 half_length--;

                                 //checking for uniqueness of the palindrome
                                 if( map_str.find(substr)!=map_str.end())
                                 {
                                     //present;
                                     //do nothing;
                                 }
                                 else
                                 {
                                     map_str[substr]=1;
                                     cnt++;
                                 }
                             }
                         }
                         else // for even palindromes
                         {
                            center= (i/2);
                            half_length= P[i]/2;
                            while(half_length>0)
                            {
                                start= center- half_length;
                                substr= str_new.substr(start,2*half_length);
                                half_length--;
                                //checking for uniqueness of the palindrome
                                 if( map_str.find(substr)!=map_str.end())
                                 {
                                     //present;
                                     //do nothing;
                                 }
                                 else
                                 {
                                     map_str[substr]=1;
                                     cnt++;
                                 }
                            }
                         }
                    }

                }
                a=cnt;
        }
        // manacher algo ended
       // cout<<"count of palindromes= "<<cnt<<endl;


        // find the number of divisors
        bigint bgsum=0;
        for(d=1;d*d<=n;d++)
        {
            bigint bg1=1;
            if(n%d==0)
            { // d is a factor

                x= phi(d);

                for(i=1;i<=n/d;i++)
                {
                    bg1=bg1*a;
                }
                bgsum= bgsum+ bg1*x;
                if(d*d!=n)
                { // n/d is divisor
                    bigint bg1=1;
                    x= phi(n/d);

                    for(i=1;i<=d;i++)
                    {
                        bg1=bg1*a;
                    }
                    bgsum= bgsum+ bg1*x;

                    // n/d is factor
                }
            }
        }
        if(n%2==1) // for odd
        {
            bigint bg2=n;
            for(i=1;i<=(n+1)/2;i++)
            {
                bg2*=a;
            }
            bgsum= bgsum+bg2;
        }
        else // for even
        {
            bigint bg3= (n/2)*(a+1);
            for(i=1;i<=n/2;i++)
            {
                bg3= bg3*a;
            }
            bgsum+= bg3;
        }

        bgsum= (bgsum)/(2*n);
        cout<<bgsum<<endl;
return 0;
}

