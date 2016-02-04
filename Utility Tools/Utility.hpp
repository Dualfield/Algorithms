#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define lp(i,a,b)for(auto i=a;i<=b;++i)
void read(string a){
    freopen(a.c_str(),"r",stdin);
}
void write(string a){
    freopen(a.c_str(),"w",stdout);
}
template<class T>T read(){
    T a;
    cin>>a;
    return a;
}
void sync(int t){
    ios::sync_with_stdio(t);
}
template<class T1,class T2>ostream&operator<<(ostream&s,const pair<T1,T2>&a){
    return s<<a.first<<" "<<a.second;
}
template<class T1,class T2,class T3>struct triple{
    triple(T1 a,T2 b,T3 c):
        first(a),second(b),third(c){
    }
    T1 first;
    T2 second;
    T3 third;
};
template<class T1,class T2,class T3>ostream&operator<<(ostream&s,const triple<T1,T2,T3>&a){
    return s<<a.first<<" "<<a.second<<" "<<a.third;
}
template<class T1,class T2,class T3>triple<T1,T2,T3>make_triple(T1 a,T2 b,T3 c){
    return triple<T1,T2,T3>(a,b,c);
}
template<class T>T sum(triple<T,T,T>a){
    return a.first+a.second+a.third;
}
template<class T>T product(triple<T,T,T>a){
    return a.first*a.second*a.third;
}
template<class T>vector<T>sort(vector<T>a){
    sort(a.begin(),a.end());
    return a;
}
template<class T,class F>vector<T>foreach(vector<T>a,F f){
    for(int i=0;i<a.size();++i)
        f(a[i]);
    return a;
}
template<class T>T sum(const vector<T>&a){
    T r=0;
    for(int i=0;i<a.size();++i)
        r+=a[i];
    return r;
}
template<class T>ostream&operator<<(ostream&s,const vector<T>&a){
    for(int i=0;i<a.size();++i){
        if(i)
            cout<<' ';
        cout<<a[i];
    }
    return s;
}
