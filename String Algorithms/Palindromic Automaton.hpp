#include<bits/stdc++.h>
using namespace std;
struct PalindromicAutomaton{
    struct node{
        node(int m,node*f,int l):
            nxt(m),fail(f),cnt(0),len(l){
        }
        node*fail;
        int cnt,len;
        vector<node*>nxt;
    }*lst;
    PalindromicAutomaton(int _m):
        m(_m),strl(0){
        node*n0=new node(m,0,-2),*n1=new node(m,n0,-1),*n2=new node(m,n1,0);
        fill(n0->nxt.begin(),n0->nxt.end(),n2);
        str.push_back(-1);
        lst=n1;
    }
    node*getf(node*x){
        while(x->fail&&str[strl-x->len-1]!=str[strl])
            x=x->fail;
        return x;
    }
    node*add(int c){
        ++strl;
        node*p=getf(lst);
        str.push_back(c);
        if(!p->nxt[c]){
            node*np=(p->nxt[c]=new node(m,getf(p->fail)->nxt[c],p->len+2));
            nds.push_back(np);
        }
        ++(lst=p->nxt[c])->cnt;
        return lst;
    }
    void count(){
        for(int i=nds.size()-1;i>=0;--i)
            nds[i]->fail->cnt+=nds[i]->cnt;
    }
    int m,strl;
    vector<int>str;
    vector<node*>nds;
};
