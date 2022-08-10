#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
class UFDS{
    private:
    int p[30005],s[30005];
    public:
    UFDS(int n){
        for (size_t i = 1; i <=n; i++)p[i]=i;
        for (size_t i = 1; i <=n; i++)s[i]=1;
    }
    int findset(int a){return (p[a]==a)?a:(p[a]=findset(p[a]));}
    bool sameset(int a,int b){return findset(a)==findset(b);}
    void join(int a,int b){
        if(sameset(a,b))return;
        a=findset(a),b=findset(b);
        if(s[b]>s[a])swap(a,b);
        p[b]=p[a];
        s[a]+=s[b];
    }
    int getsize(int a){return s[findset(a)];}
};
int main(){
    fastio
    int n,t,m,a,b;
    cin>>t;
    for (size_t c = 0; c < t; c++)
    {
        cin>>n>>m;
        int mx=1;
        UFDS friends(n);
        for (size_t i = 0; i < m; i++)
        {
            cin>>a>>b;
            friends.join(a,b);
            mx=max(mx,friends.getsize(a));
        }
        cout<<mx<<"\n";
    }
}