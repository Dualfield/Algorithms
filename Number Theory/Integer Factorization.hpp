#include<bits/stdc++.h>
using namespace std;
namespace IntegerFactorization{
    template<class T>T mul(T x,T y,T z){
           if(typeid(T)==typeid(int))
               return (long long)x*y%z;
           else
               return (x*y-(T)(((long double)x*y+0.5)/z)*z+z)%z;
       }
       template<class T>T pow(T a,T b,T c){
           T r=1;
           for(;b;b&1?r=mul(r,a,c):0,b>>=1,a=mul(a,a,c));
           return r;
       }
       template<class T>bool chk(T a,int c=10){
           if(a==1)
               return false;
           T u=a-1,t=0;
           for(;u%2==0;u/=2,++t);
           for(int i=0;i<c;++i){
               T x=pow(T(rand()*1.0/RAND_MAX*(a-2)+1),u,a),y;
               for(int j=0;j<t;++j){
                   y=x;
                   x=mul(x,x,a);
                   if(x==1&&y!=1&&y!=a-1)
                       return false;
               }
               if(x!=1)
                   return false;
           }
           return true;
       }
       template<class T>T gcd(T a,T b){
           if(a<0)
               a=-a;
           if(b<0)
               b=-b;
           return b?gcd(b,a%b):a;
       }
       template<class T>T rho(T a,T c){
           T x=double(rand())/RAND_MAX*(a-1),y=x;
           for(int i=1,k=2;;){
               x=(mul(x,x,a)+c)%a;
               T d=gcd(y-x,a);
               if(d!=1&&d!=a)
                   return d;
               if(y==x)
                   return a;
               if(++i==k)
                   y=x,k=2*k;
           }
       }
       template<class T>vector<pair<T,int> >run(T a){
           if(a==1)
               return vector<pair<T,int> >();
           if(chk(a))
               return vector<pair<T,int> >(1,make_pair(a,1));
           T b=a;
           while((b=rho(b,T(double(rand())/RAND_MAX*(a-1))))==a);
           vector<pair<T,int> >u=fac(b),v=fac(a/b),r;
           for(int pu=0,pv=0;pu<u.size()||pv<v.size();){
               if(pu==u.size())
                   r.push_back(v[pv++]);
               else if(pv==v.size())
                   r.push_back(u[pu++]);
               else if(u[pu].first==v[pv].first)
                   r.push_back(make_pair(u[pu].first,(u[pu].second+v[pv].second))),++pu,++pv;
               else if(u[pu].first>v[pv].first)
                   r.push_back(v[pv++]);
               else
                   r.push_back(u[pu++]);}
           return r;
       }
}
