#include<bits/stdc++.h>
using namespace std;
string read_all(){
    string t;
    getline(cin,t,char(EOF));
    return t;
}
string delete_all(string a,char b){
    string r;
    for(int i=0;i<a.size();++i)
        if(a[i]!=b)
            r.push_back(a[i]);
    return r;
}
string substr(string a,int l,int r){
    return a.substr(l,r-l+1);
}
vector<string>split(string a,char b){
    vector<string>r;
    string t;
    for(int i=0;i<a.size();++i)
        if(a[i]!=b)
            t.push_back(a[i]);
        else{
            r.push_back(t);
            t="";
        }
    r.push_back(t);
    return r;
}
int letter_order(char a){
    return a>='a'&&a<='z'?a-'a'+1:a-'A'+1;
}
int letter_sum(string a){
    int r=0;
    for(int i=0;i<a.size();++i)
        r+=letter_order(a[i]);
    return r;
}
bool is_palindromic_string(string a){
    for(int i=0;i<a.size();++i)
        if(a[i]!=a[a.size()-i-1])
            return false;
    return true;
}
