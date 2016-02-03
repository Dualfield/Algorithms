#include<bits/stdc++.h>
using namespace std;
struct SuffixArray{
    int*sa,*ht,*rk,*ts,*ct,ln;
    SuffixArray(int*s){
        int m=0;
        for(ln=0;s[ln+1];)
            m=max(m,s[++ln]);
        crt(sa,ln);
        crt(ht,ln);
        crt(rk,ln);
        crt(ts,ln);
        crt(ct,max(ln,m));
        dc3(s,ln,m,sa,rk);
        for(int i=1;i<=ln;++i){
            if(rk[i]==1){
                ht[1]=0;
                continue;
            }
            int&d=ht[rk[i]]=max(i==1?0:ht[rk[i-1]]-1,0);
            for(;i+d<=ln&&sa[rk[i]-1]+d<=ln&&s[i+d]==s[sa[rk[i]-1]+d];++d);
        }
    }
    ~SuffixArray(){
        del(sa);
        del(ht);
        del(rk);
        del(ts);
        del(ct);
    }
    void crt(int*&a,int n){
        a=new int[n+1];
    }
    void del(int*a){
        delete a;
    }
    #define fc(i)(p0[i]+d>n||!p0[i]?0:s[p0[i]+d])
    int cmp(int*p0,int i,int*s,int n){
        for(int d=0;d<3;++d)
            if(fc(i)!=fc(i-1))
                return 1;
        return 0;
    }
    void sot(int*p0,int n0,int*s,int n,int m,int d){
        memset(ct,0,(m+1)*4);
        for(int i=1;i<=n0;++i)
            ++ct[fc(i)];
        for(int i=1;i<=m;++i)
            ct[i]+=ct[i-1];
        for(int i=n0;i>=1;--i)
            ts[ct[fc(i)]--]=p0[i];
        memcpy(p0+1,ts+1,n0*4);
    }
    #define fc(d)if(s[i+d]!=s[j+d])return s[i+d]<s[j+d];if(i==n-d||j==n-d)return i==n-d;
    bool cmp(int*s,int n,int*r,int i,int j){
        fc(0)
        if(j%3==1)
            return r[i+1]<r[j+1];
        fc(1)
        return r[i+2]<r[j+2];
    }
    #undef fc
    void dc3(int*s,int n,int m,int*a,int*r){
        int n0=n-(n/3)+1,*a0,*s0,i,j=0,k=n/3+bool(n%3)+1,l;
        crt(s0,n0);
        s0[k]=1;
        crt(a0,n0+1);
        a0[k]=0;
        for(i=1;i<=n;i+=3)
            a0[++j]=i,a0[j+k]=i+1;
        for(i=2;i>=0;--i)
            sot(a0,n0,s,n,m,i);
        r[a0[1]]=1;
        for(i=2;i<=n0;++i)
            r[a0[i]]=r[a0[i-1]]+cmp(a0,i,s,n);
        for(i=1,j=0;i<=n;i+=3)
            s0[++j]=r[i],s0[j+k]=r[i+1];
        if(r[a0[n0]]==n0){
            memcpy(r+1,s0+1,n0*4);
            for(i=1;i<=n0;++i)
                a0[a[i]=r[i]]=i;
        }else
            dc3(s0,n0,r[a0[n0]],a0,a);
        for(i=1,j=0;i<=n;i+=3)
            r[i]=a[++j],r[i+1]=a[j+k];
        j=0;
        if(n%3==0)
            s0[++j]=n;
        for(i=1;i<=n0;++i)
            if(a0[i]<k){
                a0[i]=3*a0[i]-2;
                if(a0[i]!=1)
                    s0[++j]=a0[i]-1;
            }else
                a0[i]=(a0[i]-k)*3-1;
        sot(s0,j,s,n,m,0);
        for(i=1,k=2,l=0;i<=j||k<=n0;)
            if(k>n0||i<=j&&cmp(s,n,r,s0[i],a0[k]))
                a[++l]=s0[i++];
            else
                a[++l]=a0[k++];
        for(i=1;i<=n;++i)
            r[a[i]]=i;
        del(a0);
        del(s0);
    }
};
