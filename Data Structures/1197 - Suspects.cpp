#include <bits/stdc++.h>

using namespace std;
#define vi vector<int>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

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

    int getSuspects(){
        int susp=0;
        for(int i=0;i<p.size();i++)
            if(sameSet(i,0)) susp++;
        return susp;
    }
};

int main(){
    fastio
    int n,m;
    while (cin>>n>>m && n+m!=0)
    {
        UFDS group(n);
        for (size_t i = 0; i < m; i++)
        {
            int k;
            cin>>k;
            int rep,tmp;
            for (size_t j = 0; j < k; j++)
            {
                if(j==0){
                    cin>>rep;
                }else{
                    cin>>tmp;
                    group.join(rep,tmp);
                }
            }
        }
        cout<<group.getSuspects()<<"\n";
    }
}