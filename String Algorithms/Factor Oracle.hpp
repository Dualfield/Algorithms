#include<bits/stdc++.h>
using namespace std;
template<class T,int N,int M,T D>struct FactorOracle{
    FactorOracle(){
        memset(tr,(lrs[0]=0,sp[0]=-1),4*M);
    }
    void insert(const T*s,int n){
        for(int i=0,c=s[i]-D;i<n;c=s[++i]-D){
            memset(tr+i+1,(lrs[i+1]=0)-1,4*M);
            int j=sp[i],p1=(tr[i][c]=i+1)-1;
            for(;j>-1&&tr[j][c]<0;tr[j][c]=i+1,j=sp[p1=j]);
            sp[i+1]=j<0?0:tr[j][c];
            if(sp[i+1]){
                int p2=sp[i+1]-1==sp[p1]?p1:sp[i+1]-1;
                for(;sp[p1]!=sp[p2];p2=sp[p2]);
                lrs[i+1]=min(lrs[p1],lrs[p2])+1;
            }
        }
    }
    int sp[N+1],lrs[N+1],tr[N+1][M];
};
