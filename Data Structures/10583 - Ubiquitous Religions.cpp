#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
class UFDS{
    private:
    int p[50005],s[50005];
    public:
    size_t sets;
    UFDS(int n){
        sets=n;
        for(size_t i=1;i<=n;i++)p[i]=i;
        for(size_t i=1;i<=n;i++)s[i]=1;
    }
    int findset(int a){return (p[a]==a)?a:(p[a]=findset(p[a]));}
    bool sameset(int a,int b){return findset(a)==findset(b);}
    void join(int a,int b){
        if(sameset(a,b))return;
        --sets;
        a=findset(a),b=findset(b);
        if(s[b]>s[a])swap(a,b);
        p[b]=p[a];
        s[a]+=s[b];
    }
};
int main(){
    fastio
    int n,m,t=1;
    while (cin>>n>>m)
    {
        if(n==0 && m==0)break;
        UFDS religions(n);
        int a,b;
        for (size_t i = 0; i < m; i++)
        {
            cin>>a>>b;
            religions.join(a,b);
        }
        cout<<"Case "<<t++<<": "<<religions.sets<<"\n";
    }
}