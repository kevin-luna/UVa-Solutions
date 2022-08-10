#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
class UFDS{
    private: 
    map<string,string> p;
    map<string,int> s;
    public:
    int size(string i){return s[findSet(i)];}
    bool exist(string i){return p.count(i)>0;}
    void insert(string i){
        if(exist(i))return;
        p[i]=i;
        s[i]=1;
    }
    void reset(){p.clear();s.clear();}
    string findSet(string i){return (p[i]==i) ? i:(p[i]=findSet(p[i]));}
    bool sameSet(string i,string j){return findSet(i)==findSet(j);}
    void join(string i,string j){
        if(sameSet(i,j))return;
        i = findSet(i);
        j = findSet(j);
        if(s[i]<s[j])swap(i,j);
        s[i]+=s[j];
        p[j]=i;
    }
};
int main(){
    fastio
    int c,r;
    UFDS chains;
    string name1,name2;
    name1.reserve(31);
    name2.reserve(31);
    while(cin>>c>>r){
        if(c==0 && r==0)break;
        int mx=1;
        for (size_t i = 0; i < c; i++)
        {
            cin>>name1;
            chains.insert(name1);
        }
        for (size_t i = 0; i < r; i++)
        {
            cin>>name1>>name2;
            chains.join(name2,name1);
            mx=max(mx,chains.size(name2));
        }
        cout<<mx<<"\n";
        chains.reset();
    }
}