#include<bits/stdc++.h>
using namespace std;
template<class T,T P,int D=0>struct ModularInteger{
    ModularInteger(T t=0):v(t){
        if(v<0||v>=P)
            v=(v%P+P)%P;
    }
    ModularInteger<T,P,D>operator=(T a){
        v=a;
        if(v<0||v>=P)
            v%=P;
        return*this;
    }
    ModularInteger<T,P,D>operator-(){
        return v?P-v:0;
    }
    ModularInteger<T,P,D>&operator+=(ModularInteger<T,P,D>a){
        *this=*this+a;
        return*this;
    }
    ModularInteger<T,P,D>&operator-=(ModularInteger<T,P,D>a){
        *this=*this-a;
        return*this;
    }
    ModularInteger<T,P,D>&operator*=(ModularInteger<T,P,D>a){
        *this=*this*a;
        return*this;
    }
    ModularInteger<T,P,D>&operator/=(ModularInteger<T,P,D>a){
        *this=*this/a;
        return*this;
    }
    T v;
};
template<class T,T P,int D>ModularInteger<T,P,D>pow(ModularInteger<T,P,D>a,long long b){
    ModularInteger<T,P,D>r(1);
    for(;b;b>>=1,a=a*a)
        if(b&1)
            r=r*a;
    return r;
}
template<class T,T P,int D>ModularInteger<T,P,D>inv(ModularInteger<T,P,D>a){
    return pow(a,P-2);
}
template<class T,T P,int D>vector<ModularInteger<T,P,D> >sqrt(ModularInteger<T,P,D>a){
    vector<ModularInteger<T,P,D> >r;
    if(!a.v)
        r.push_back(ModularInteger<T,P,D>(0));
    else if(pow(a,P-1>>1).v==1){
        int s=P-1,t=0;
        ModularInteger<T,P,D>b=1;
        for(;pow(b,P-1>>1).v!=P-1;b=rand()*1.0/RAND_MAX*(P-1));
        for(;s%2==0;++t,s/=2);
        ModularInteger<T,P,D>x=pow(a,(s+1)/2),e=pow(a,s);
        for(int i=1;i<t;++i,e=x*x/a)
            if(pow(e,1<<t-i-1).v!=1)
                x=x*pow(b,(1<<i-1)*s);
        r.push_back(x);
        r.push_back(-x);
    }
    return r;
}
template<class T,T P,int D>ModularInteger<T,P,D>operator+(ModularInteger<T,P,D>a,ModularInteger<T,P,D>b){
    ModularInteger<T,P,D>c(a.v+b.v);
    if(c.v>=P)
        c.v-=P;
    return c;
}
template<class T,T P,int D>ModularInteger<T,P,D>operator-(ModularInteger<T,P,D>a,ModularInteger<T,P,D>b){
    ModularInteger<T,P,D>c(a.v-b.v);
    if(c.v<0)
        c.v+=P;
    return c;
}
template<class T,T P,int D>ModularInteger<T,P,D>operator*(ModularInteger<T,P,D>a,ModularInteger<T,P,D>b){
    if(D)
        return ModularInteger<T,P,D>((a.v*b.v-(long long )(((long double)a.v*b.v+0.5)/P)*P+P)%P);
    else
        return ModularInteger<T,P,D>((long long)a.v*b.v%P);
}
template<class T,T P,int D>ModularInteger<T,P,D>operator/(ModularInteger<T,P,D>a,ModularInteger<T,P,D>b){
    return a*inv(b);
}
template<class T,T P,int D>bool operator==(ModularInteger<T,P,D>a,ModularInteger<T,P,D>b){
    return a.v==b.v;
}
template<class T,T P,int D>bool operator!=(ModularInteger<T,P,D>a,ModularInteger<T,P,D>b){
    return a.v!=b.v;
}
template<class T,T P,int D>istream&operator>>(istream&s,ModularInteger<T,P,D>&a){
    s>>a.v;
    return s;
}
template<class T,T P,int D>ostream&operator<<(ostream&s,ModularInteger<T,P,D>a){
    s<<a.v;
    if(a.v>=P||a.v<0)
        a.v%=P;
    return s;
}
