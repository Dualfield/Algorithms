#include<bits/stdc++.h>
using namespace std;
template<class T>struct ConvexHull{
    struct point{
        T x,y;
        point(T _x,T _y):
            x(_x),y(_y){
        }
        point operator-(point a){
            return point(x-a.x,y-a.y);
        }
        T operator*(point a){
            return x*a.y-y*a.x;
        }
        int operator<(point a){
            return x==a.x?y<a.y:x<a.x;
        }
    };
    static int check(point a,point b,point c){
        return (a-c)*(b-c)<=0;
    }
    static vector<vector<point> >run(vector<point>a){
        sort(a.begin(),a.end());
        vector<point>u,d;
        for(int i=0;i<a.size();u.push_back(a[i++]))
            while(u.size()>1&&check(a[i],u.back(),u[u.size()-2]))
                u.pop_back();
        for(int i=int(a.size()-1);i>=0;d.push_back(a[i--]))
            while(d.size()>1&&check(a[i],d.back(),d[d.size()-2]))
                d.pop_back();
        vector<vector<point> >r;
        r.push_back(u);
        r.push_back(d);
        return r;
    }
};
