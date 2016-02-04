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
template<class T1,class T2>T2 convert(T1 a){
    stringstream s;
    s<<a;
    T2 t;
    s>>t;
    return t;
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
template<class T>T sum(const set<T>&a){
    T r=0;
    for(typename set<T>::iterator i=a.begin();i!=a.end();++i)
        r+=*i;
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
template<class T>vector<T>unique(vector<T>a){
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    return a;
}
template<class T>vector<T>combination(T a){
    vector<T>r;
    for(int i=0;i<(1<<a.size());++i){
        T t;
        for(int j=0;j<a.size();++j)
            if((i>>j)&1)
                t.push_back(a[j]);
        r.push_back(t);
    }
    return r;
}
template<class T>vector<T>permutation(T a){
    sort(a.begin(),a.end());
    vector<T>r;
    for(int i=0;i<(1<<a.size());++i){
        T t;
        for(int j=0;j<a.size();++j)
            if((i>>j)&1)
                t.push_back(a[j]);
        do{
            r.push_back(t);
        }while(next_permutation(t.begin(),t.end()));
    }
    return r;
}
template<class T>set<T>operator+(set<T>a,set<T>b){
    for(typename set<T>::iterator i=a.begin();i!=a.end();++i)
        b.insert(*i);
    return b;
}
