#include <bits/stdc++.h>
#define vi vector<int>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

class UFDS{
    private: vi p,r;
    public:
    UFDS(int n){
        r.assign(n+1,0);
        p.assign(n+1,0);
        for(int i=1;i<=n;i++) p[i]=i;
    }

    int findSet(int i){
        return (p[i]==i) ? i:(p[i]=findSet(p[i]));
    }

    bool sameSet(int i,int j){
        return findSet(i)==findSet(j);
    }

    void join(int i,int j){
        if(!sameSet(i,j)){
            int si=findSet(i),sj=findSet(j);
            if(r[si]>r[sj])p[sj]=si;
            else{
                p[si]=sj;
                if(r[si]==r[sj])r[sj]++;
            }
        }
    }
};

int main(){
    int t;
    cin>>t;
    for (int c = 1; c <= t; c++)
    {
        if(c>1) cout<<"\n";
        int comp,succ=0,unsucc=0;
        cin>>comp;
        cin.ignore();
        UFDS ufds(comp);
        string line;
        while (getline(cin,line) && line.length()>2)
        {
            stringstream in(line);
            char op;int c1,c2;
            while (in>>op>>c1>>c2)
            {
                if(op=='c') ufds.join(c1,c2);
                else (ufds.sameSet(c1,c2) ? succ++:unsucc++);
            }
        }
        cout<<succ<<","<<unsucc<<"\n";
    }
    
}