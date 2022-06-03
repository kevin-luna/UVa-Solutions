#include <bits/stdc++.h>

using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vi vector<int>

void solve(vi &bs,int p,int &h,int &ones){
    if(p>=bs.size()){
        if(ones==h){
            for (auto &e : bs)
            {
                cout<<e;
            }
            cout<<"\n";
            return;
        }
        return;
    }
    bs[p]=0;
    solve(bs,p+1,h,ones);

    bs[p]=1;
    ++ones;
    solve(bs,p+1,h,ones);
    // bs[p]=0;
    --ones;
}

int main(){
    fastio
    int d,n,h,ones;
    cin>>d;
    vi bitseq;
    for (int i = 1; i <= d; i++)
    {
        if(i>1) cout<<"\n";
        cin>>n>>h;
        bitseq.assign(n,0);
        ones=0;
        solve(bitseq,0,h,ones);
    }
}