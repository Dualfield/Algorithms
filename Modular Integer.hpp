#include<bits/stdc++.h>
using namespace std;
template<class T,T P>struct ModularInteger{
    ModularInteger(T t=0):v(t){
        if(v<0||v>=P)
            v=(v%P+P)%P;
    }
    ModularInteger<T,P>&operator=(T a){
        v=a;
        if(v<0||v>=P)
            v%=P;
        return*this;
    }
    ModularInteger<T,P>operator-(){
        return v?P-v:0;
    }
    ModularInteger<T,P>&operator+=(ModularInteger<T,P>a){
        return*this=*this+a;
    }
    ModularInteger<T,P>&operator-=(ModularInteger<T,P>a){
        return*this=*this-a;
    }
    ModularInteger<T,P>&operator*=(ModularInteger<T,P>a){
        return*this=*this*a;
    }
    ModularInteger<T,P>&operator/=(ModularInteger<T,P>a){
        return*this=*this/a;
    }
    T v;
};
template<class T,T P>ModularInteger<T,P>pow(ModularInteger<T,P>a,long long b){
    ModularInteger<T,P>r(1);
    for(;b;b>>=1,a=a*a)
        if(b&1)
            r=r*a;
    return r;
}
template<class T,T P>ModularInteger<T,P>inv(ModularInteger<T,P>a){
    return pow(a,P-2);
}
template<class T,T P>vector<ModularInteger<T,P> >sqrt(ModularInteger<T,P>a){
    vector<ModularInteger<T,P> >r;
    if(!a.v)
        r.push_back(ModularInteger<T,P>(0));
    else if(pow(a,P-1>>1).v==1){
        int s=P-1,t=0;
        ModularInteger<T,P>b=1;
        for(;pow(b,P-1>>1).v!=P-1;b=rand()*1.0/RAND_MAX*(P-1));
        for(;s%2==0;++t,s/=2);
        ModularInteger<T,P>x=pow(a,(s+1)/2),e=pow(a,s);
        for(int i=1;i<t;++i,e=x*x/a)
            if(pow(e,1<<t-i-1).v!=1)
                x=x*pow(b,(1<<i-1)*s);
        r.push_back(x);
        r.push_back(-x);
    }
    return r;
}
template<class T,T P>ModularInteger<T,P>operator+(ModularInteger<T,P>a,ModularInteger<T,P>b){
    ModularInteger<T,P>c(a.v+b.v);
    if(c.v>=P)
        c.v-=P;
    return c;
}
template<class T,T P>ModularInteger<T,P>operator-(ModularInteger<T,P>a,ModularInteger<T,P>b){
    ModularInteger<T,P>c(a.v-b.v);
    if(c.v<0)
        c.v+=P;
    return c;
}
template<class T,T P>ModularInteger<T,P>operator*(ModularInteger<T,P>a,ModularInteger<T,P>b){
    if(typeid(T)!=typeid(int))
        return ModularInteger<T,P>((a.v*b.v-(long long )(((long double)a.v*b.v+0.5)/P)*P+P)%P);
    else
        return ModularInteger<T,P>((long long)a.v*b.v%P);
}
template<class T,T P>ModularInteger<T,P>operator/(ModularInteger<T,P>a,ModularInteger<T,P>b){
    return a*inv(b);
}
template<class T,T P>bool operator==(ModularInteger<T,P>a,ModularInteger<T,P>b){
    return a.v==b.v;
}
template<class T,T P>bool operator!=(ModularInteger<T,P>a,ModularInteger<T,P>b){
    return a.v!=b.v;
}
template<class T,T P>istream&operator>>(istream&s,ModularInteger<T,P>&a){
    s>>a.v;
    return s;
}
template<class T,T P>ostream&operator<<(ostream&s,ModularInteger<T,P>a){
    s<<a.v;
    if(a.v<0||a.v>=P)
        a.v%=P;
    return s;
}
