#include<bits/stdc++.h>
using namespace std;
template<class T>struct StringSearching{
    StringSearching(T*a):
        b(2,a[1]),f(2),l(2){
        for(int i=0;a[l]?1:(--l,0);b.push_back(a[l++])){
            for(;i&&a[i+1]!=a[l];i=f[i]);
            f.push_back(i=i+(a[i+1]==a[l]));
        }
        for(int i=2;i<l;++i)
            if(a[f[i]+1]==a[i+1])
                f[i]=f[f[i]];
    }
    int run(T*a,int p){
        for(int i=p?p+l:1,j=p?f[l]:0;a[i];++i){
            for(;j&&b[j+1]!=a[i];j=f[j]);
            if((j+=b[j+1]==a[i])==l)
                return i-l+1;
        }
        return 0;
    }
    int l;
    vector<T>b;
    vector<int>f;
};
