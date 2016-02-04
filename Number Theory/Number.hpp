#include<bits/stdc++.h>
using namespace std;
template<class T>T add(T a,T b,T p){
    return a+b<p?a+b:a+b-p;
}
template<class T>T sub(T a,T b,T p){
    return a-b<0?a-b+p:a-b;
}
template<class T>T mul(T a,T b,T p){
    if(typeid(T)==typeid(int))
        return (long long)a*b%p;
    else
        return (a*b-(T)(((long double)a*b+0.5)/p)*p+p)%p;
}
template<class T>T pow(T a,T b,T p){
    T r=1;
    for(;b;b&1?r=mul(r,a,p):0,b>>=1,a=mul(a,a,p));
    return r;
}
template<class T>T inv(T a,T p){
    return pow(a,p-2,p);
}
template<class T>T div(T a,T b,T p){
    return mul(a,inv(b,p),p);
}
template<class T>T gcd(T a,T b){
    if(a<0)
        return gcd(-a,b);
    if(b<0)
        return gcd(a,-b);
    return b?gcd(b,a%b):a;
}
template<class T>pair<T,T>exgcd(T a,T b){
    if(!b)
        return make_pair(T(1),T(0));
    pair<T,T>t=exgcd(b,a%b);
    swap(t.first,t.second);
    t.second-=a/b*t.first;
    return t;
}
template<class T>vector<T>divisor(T a){
    vector<T>t;
    for(T d=1;d*d<=a;++d)
        if(a%d==0){
            t.push_back(d);
            if(d*d!=a)
                t.push_back(a/d);
        }
    return t;
}
template<class T>vector<pair<T,T> >factor(T a){
    vector<pair<T,T> >t;
    T b=a;
    for(T d=2;d*d<=a;++d)
        if(b%d==0)
            for(t.push_back(make_pair(d,T(0)));b%d==0;b/=d,++t.back().second);
    if(b!=1)
        t.push_back(make_pair(b,T(1)));
    return t;
}
template<class T>bool is_prime(T a){
    if(a<2)
        return false;
    for(T d=2;d*d<=a;++d)
        if(a%d==0)
            return false;
    return true;
}
template<class T>bool is_palindromic_number(T a){
    string b;
    stringstream s;
    s<<a;
    s>>b;
    for(int i=0;i<b.size();++i)
        if(b[i]!=b[b.size()-i-1])
            return false;
    return true;
}
template<class T>T pow(T a,T b){
    T r=1;
    for(T i=1;i<=b;++i)
        r*=a;
    return r;
}
template<class T>T power_sum(T n,T k){
    T r=0;
    for(T i=1;i<=n;++i)
        r+=pow(i,k);
    return r;
}
template<class T>T sqr(T a){
    return a*a;
}
int nth_prime(int n){
    int r=1;
    for(int i=1;i<=n;++i)
        for(++r;!is_prime(r);++r);
    return r;
}

vector<vector<int> >pythagorean_triple(int n){
    vector<vector<int> >t;
    for(int i=1;i*i<=n;++i)
        for(int j=1;j<i&&i*i+j*j<=n;++j){
            vector<int>u;
            u.push_back(i*i-j*j);
            u.push_back(2*i*j);
            u.push_back(i*i+j*j);
            t.push_back(u);
        }
    return t;
}
vector<vector<int> >primitive_pythagorean_triple(int n){
    vector<vector<int> >t;
    for(int i=1;i*i<=n;++i)
        for(int j=1;j<i&&i*i+j*j<=n;++j)
            if((i-j)%2&&gcd(i,j)==1){
                vector<int>u;
                u.push_back(i*i-j*j);
                u.push_back(2*i*j);
                u.push_back(i*i+j*j);
                t.push_back(u);
            }
    return t;
}
template<class T>nth_triangular(T n){
    if(n%2==0)
        return n/2*(n+1);
    else
        return (n+1)/2*n;
}
template<class T>vector<T>collatz_sequence(T a){
    vector<T>t;
    do{
        t.push_back(a);
        if(a==1)
            return t;
        if(a%2==0)
            a/=2;
        else
            a=3*a+1;
    }while(1);
}
template<class T>T factorial(T n){
    T r=1;
    for(T i=1;i<=n;++i)
        r*=i;
    return r;
}
template<class T>T product(T a,T b){
    T r=1;
    for(T i=a;i<=b;++i)
        r*=i;
    return r;
}
template<class T>T C(T n,T k){
    return factorial(n)/factorial(k)/factorial(n-k);
}
template<class T>T P(T n,T k){
    return factorial(n)/factorial(n-k);
}
vector<int>prime(int n){
     vector<int>p,ntp(n+1);
     ntp[1]=1;
     for(int i=2;i<=n;++i){
         if(!ntp[i])
             p.push_back(i);
         for(int j=0;j<p.size()&&p[j]*i<=n;++j){
             ntp[p[j]*i]=1;
             if(i%p[j]==0)
                 break;
         }
     }
     return p;
 }
template<class T>T digit_sum(T a){
    T r=0;
    for(;a;r+=a%10,a/=10);
    return r;
}
template<class T>T digit_power_sum(T a,T b){
    T r=0;
    for(;a;r+=pow(a%10,b),a/=10);
    return r;
}
template<class T>T divisor_sum(T a){
    vector<T>d=divisor(a);
    T s=0;
    for(int i=0;i<d.size();++i)
        s+=d[i];
    return s;
}
template<class T>bool is_perfect(T a){
    return a*2==divisor_sum(a);
}
template<class T>bool is_deficient(T a){
    return a*2>divisor_sum(a);
}
template<class T>bool is_abundant(T a){
    return a*2<divisor_sum(a);
}
template<class T>set<int>digit_set(T a){
    set<int>r;
    for(;a;r.insert(a%10),a/=10);
    return r;
}
template<class T>int digit_count(T a){
    int r=0;
    if(!a)
        ++r;
    for(;a;++r,a/=10);
    return r;
}
template<class T>T digit_factorial_sum(T a){
    T r=0;
    for(;a;r+=factorial(a%10),a/=10);
    return r;
}
template<class T>bool is_pandigital(T a){
    return digit_count(a)==digit_set(a).size();
}
template<class T>bool has_zero(T a){
    if(!a)
        return true;
    while(a){
        if(a%10==0)
            return true;
        a/=10;
    }
    return false;
}
template<class T>T right_circular_shift(T a){
    stringstream ss;
    ss<<a;
    string t;
    ss>>t;
    t=t.substr(t.size()-1,1)+t.substr(0,t.size()-1);
    ss<<t;
    ss>>a;
    return a;
}
template<class T>bool is_circular_prime(T a){
    for(int i=digit_count(a);i;--i,a=right_circular_shift(a))
        if(!is_prime(a))
            return false;
    return true;
}
template<class T>string to_binary(T a){
    string r;
    while(a){
        r.push_back(a%2+'0');
        a/=2;
    }
    reverse(r.begin(),r.end());
    return r;
}
