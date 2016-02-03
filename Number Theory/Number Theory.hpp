#include<bits/stdc++.h>
using namespace std;
namespace NumberTheory{
    struct BigInteger operator+(BigInteger a,BigInteger b);
    BigInteger operator+(BigInteger a,int b);
    BigInteger operator-(BigInteger a,BigInteger b);
    BigInteger operator*(BigInteger a,BigInteger b);
    BigInteger operator*(BigInteger a,BigInteger b);
    BigInteger operator/(BigInteger a,BigInteger b);
    BigInteger operator%(BigInteger a,BigInteger b);
    BigInteger operator%(BigInteger a,int b);
    bool operator!=(BigInteger a,int b);
    struct BigInteger{
        operator bool(){
            return *this!=0;
        }
        BigInteger(long long a=0){
            if(a<0){
                s=-1;
                a=-a;
            }else
                s=a!=0;
            do{
                d.push_back(a%B);
                a/=B;
            }while(a);
        }
        BigInteger(string a){
            s=(a[0]=='-')?-1:(a!="0");
            for(int i=a.size()-1;i>=(a[0]=='-');i-=L){
                int t=0,j=max(i-L+1,int(a[0]=='-'));
                for(int k=j;k<=i;++k)
                    t=t*10+a[k]-'0';
                d.push_back(t);
            }
        }
        BigInteger&operator=(long long a){
            return*this=BigInteger(a);
        }
        BigInteger&operator+=(BigInteger a){
            return*this=*this+a;
        }
        BigInteger&operator-=(BigInteger a){
            return*this=*this-a;
        }
        BigInteger&operator*=(BigInteger a){
            return*this=*this*a;
        }
        BigInteger&operator/=(BigInteger a){
            return*this=*this/a;
        }
        BigInteger&operator%=(BigInteger a){
            return*this=*this%a;
        }
        BigInteger&operator++(){
            return*this=*this+1;
        }
        int s;
        vector<int>d;
        static const int B=1e8,L=8;
    };
    bool operator<(BigInteger a,BigInteger b){
        if(a.s!=b.s)
            return a.s<b.s;
        if(a.d.size()!=b.d.size())
            return (a.s!=1)^(a.d.size()<b.d.size());
        for(int i=a.d.size()-1;i>=0;--i)
            if(a.d[i]!=b.d[i])
                return (a.s!=1)^(a.d[i]<b.d[i]);
        return false;
    }
    bool operator>(BigInteger a,BigInteger b){
        return b<a;
    }
    bool operator<=(BigInteger a,BigInteger b){
        return !(a>b);
    }
    bool operator>=(BigInteger a,BigInteger b){
        return !(a<b);
    }
    bool operator==(BigInteger a,BigInteger b){
        return !(a<b)&&!(a>b);
    }
    bool operator!=(BigInteger a,BigInteger b){
        return !(a==b);
    }
    istream&operator>>(istream&s,BigInteger&a){
        string t;
        s>>t;
        a=BigInteger(t);
        return s;
    }
    ostream&operator<<(ostream&s,BigInteger a){
        if(a.s==-1)
            s<<'-';
        for(int i=a.d.size()-1;i>=0;--i){
            if(i!=a.d.size()-1)
                s<<setw(BigInteger::L)<<setfill('0');
            s<<a.d[i];
        }
        s<<setw(0)<<setfill(' ');
        return s;
    }
    void dzero(BigInteger&a){
        while(a.d.size()>1&&a.d.back()==0)
            a.d.pop_back();
    }
    BigInteger operator-(BigInteger a){
        a.s*=-1;
        if(a.d.size()==1&&a.d[0]==0)
            a.s=1;
        return a;
    }
    BigInteger operator+(BigInteger a,int b){
        return a+BigInteger(b);
    }
    BigInteger operator*(BigInteger a,int b){
        return a*BigInteger(b);
    }
    BigInteger operator%(BigInteger a,int b){
        return a%BigInteger(b);
    }
    bool operator!=(BigInteger a,int b){
        return a!=BigInteger(b);
    }
    BigInteger operator+(BigInteger a,BigInteger b){
        if(a.s*b.s!=-1){
            BigInteger c;c.s=a.s?a.s:b.s;
            c.d.resize(max(a.d.size(),b.d.size())+1);
            for(int i=0;i<c.d.size()-1;++i){
                if(i<a.d.size())
                    c.d[i]+=a.d[i];
                if(i<b.d.size())
                    c.d[i]+=b.d[i];
                if(c.d[i]>=BigInteger::B){
                    c.d[i]-=BigInteger::B;
                    ++c.d[i+1];
                }
            }
            dzero(c);
            return c;
        }
        return a-(-b);
    }
    BigInteger operator-(BigInteger a,BigInteger b){
        if(a.s*b.s==1){
            if(a.s==-1)
                return (-b)-(-a);
            if(a<b)
                return -(b-a);
            if(a==b)
                return 0;
            for(int i=0;i<b.d.size();++i){
                a.d[i]-=b.d[i];
                if(a.d[i]<0){
                    a.d[i]+=BigInteger::B;
                    --a.d[i+1];
                }
            }
            dzero(a);
            return a;
        }
        return a+(-b);
    }
    BigInteger operator*(BigInteger a,BigInteger b){
        vector<long long>t(a.d.size()+b.d.size());
        for(int i=0;i<a.d.size();++i)
            for(int j=0;j<b.d.size();++j)
                t[i+j]+=(long long)a.d[i]*b.d[j];
        for(int i=0;i<t.size()-1;++i){
            t[i+1]+=t[i]/BigInteger::B;
            t[i]%=BigInteger::B;
        }
        BigInteger c;
        c.s=a.s*b.s;c.d.resize(t.size());
        copy(t.begin(),t.end(),c.d.begin());
        dzero(c);
        return c;
    }
    BigInteger div2(BigInteger a){
        for(int i=a.d.size()-1;i>=0;--i){
            if(i)
                a.d[i-1]+=(a.d[i]&1)*BigInteger::B;
            a.d[i]>>=1;
        }
        dzero(a);
        if(a.d.size()==1&&a.d[0]==0)
            a.s=0;
        return a;
    }
    BigInteger operator/(BigInteger a,BigInteger b){
        if(!a.s)
            return 0;
        if(a.s<0)
            return-((-a)/b);
        if(a<b)
            return 0;
        BigInteger l=1,r=1;
        while(r*b<=a)
            r=r*2;
        while(l+1<r){
            BigInteger m=div2(l+r);
            if(m*b>a)
                r=m;
            else
                l=m;
        }
        return l;
    }
    BigInteger operator%(BigInteger a,BigInteger b){
        return a-a/b*b;
    }
    BigInteger gcd(BigInteger a,BigInteger b){
        BigInteger r=1;
        while(a!=0&&b!=0){
            if(!(a.d[0]&1)&&!(b.d[0]&1)){
                a=div2(a);
                b=div2(b);
                r=r*2;
            }else if(!(a.d[0]&1))
                a=div2(a);
            else if(!(b.d[0]&1))
                b=div2(b);
            else{
                if(a<b)
                    swap(a,b);
                a=div2(a-b);
            }
        }
        if(a!=0)
            return r*a;
        return r*b;
    }
    template<class T>T read(){
        T a;
        cin>>a;
        return a;
    }
    typedef long long ll;
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
    template<class T>bool is_palindromic(T a){
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
    template<class T1,class T2,class T3>struct triple{
        triple(T1 a,T2 b,T3 c):
            first(a),second(b),third(c){
        }
        T1 first;
        T2 second;
        T3 third;
    };
    template<class T1,class T2,class T3>triple<T1,T2,T3>make_triple(T1 a,T2 b,T3 c){
        return triple<T1,T2,T3>(a,b,c);
    }
    vector<triple<int,int,int> >pythagorean_triple(int n){
        vector<triple<int,int,int> >t;
        for(int i=1;i*i<=n;++i)
            for(int j=1;j<i&&i*i+j*j<=n;++j)
                t.push_back(make_triple(i*i-j*j,2*i*j,i*i+j*j));
        return t;
    }
    vector<triple<int,int,int> >primitive_pythagorean_triple(int n){
        vector<triple<int,int,int> >t;
        for(int i=1;i*i<=n;++i)
            for(int j=1;j<i&&i*i+j*j<=n;++j)
                if((i-j)%2&&gcd(i,j)==1)
                    t.push_back(make_triple(i*i-j*j,2*i*j,i*i+j*j));
        return t;
    }
    template<class T1,class T2>ostream&operator<<(ostream&s,const pair<T1,T2>&a){
        return s<<a.first<<" "<<a.second;
    }
    template<class T1,class T2,class T3>ostream&operator<<(ostream&s,const triple<T1,T2,T3>&a){
        return s<<a.first<<" "<<a.second<<" "<<a.third;
    }
    template<class T>T sum(triple<T,T,T>a){
        return a.first+a.second+a.third;
    }
    template<class T>T product(triple<T,T,T>a){
        return a.first*a.second*a.third;
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
    template<class T>ostream&operator<<(ostream&s,const vector<T>&a){
        for(int i=0;i<a.size();++i){
            if(i)
                cout<<' ';
            cout<<a[i];
        }
        return s;
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
}
