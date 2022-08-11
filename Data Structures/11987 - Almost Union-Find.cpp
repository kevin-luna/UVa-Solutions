#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
class UFDS{
    private:
        int parent[200005],size[200005],sum[200005];
    public:
    UFDS(int n){
        for (size_t i = 1; i <= n; i++){
            parent[i]=100000+i;
            parent[100000+i]=100000+i;
            size[100000+i]=1;
            sum[100000+i]=i;
        }
    }
    int findset(int a){
        return (parent[a]==a)? a:(parent[a]=findset(parent[a]));
    }
    bool sameset(int a,int b){return findset(a)==findset(b);}
    void status(int a){a=findset(a);cout<<size[a]<<" "<<sum[a]<<"\n";}
    void join(int a,int b){
        if(sameset(a,b))return;
        a=findset(a),b=findset(b);
        if(size[b]>size[a])swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
        sum[a]+=sum[b];
    }
    void move(int a,int b){
        if(sameset(a,b))return;
        int pa=findset(a),pb=findset(b);
        parent[a]=pb;
        --size[pa];
        ++size[pb];
        sum[pa]-=a;
        sum[pb]+=a;
    }
};
int main(){
    fastio
    int n,m;
    while (cin>>n>>m)
    {
        UFDS disjointset(n);
        int command,p,q;
        for (size_t i = 0; i < m; i++)
        {
            cin>>command>>p;
            if(command==3){
                disjointset.status(p);
            }else{
                cin>>q;
                if(command==1)disjointset.join(p,q);
                else disjointset.move(p,q);
            }
        }
    }
}