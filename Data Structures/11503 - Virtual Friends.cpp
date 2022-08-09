#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef map<string,string> mss;
typedef map<string,int> msi;
class UFDS{
    private: 
    mss p;
    msi s;
    public:

    int size(string i){
        return s[i];
    }

    bool exist(string i){
        return p.count(i)>0;
    }

    void insert(string i){
        if(exist(i))return;
        p[i]=i;
        s[i]=1;
    }

    void reset(){
        p.clear();
        s.clear();
    }

    string findSet(string i){
        return (p[i]==i) ? i:(p[i]=findSet(p[i]));
    }

    bool sameSet(string i,string j){
        return findSet(i)==findSet(j);
    }

    void join(string i,string j){
        i = findSet(i);
        j = findSet(j);
        if(s[i]<s[j])swap(i,j);
        s[i]+=s[j];
        p[j]=i;
    }
};
int main(){
    fastio
    int t,f;
    cin>>t;
    UFDS networks;
    for (size_t c = 0; c < t; c++)
    {
        cin>>f;
        string f1,f2;
        for (size_t i = 0; i < f; i++)
        {
            cin>>f1>>f2;
            networks.insert(f1);
            networks.insert(f2);
            if(!networks.sameSet(f1,f2)){
                networks.join(f1,f2);
            }
            cout<<networks.size(networks.findSet(f2))<<"\n";
        }
        networks.reset();
    }
}