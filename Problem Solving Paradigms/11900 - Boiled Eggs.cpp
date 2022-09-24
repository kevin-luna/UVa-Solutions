#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
    int t,n,p,q,w,ans;
    int e[35];
    cin>>t;
    for (size_t c = 1; c <= t; c++)
    {
        cin>>n>>p>>q;
        ans=0,w=0;
        for (size_t i = 0; i < n; i++)
        {
            cin>>e[i];
            if(ans+1<=p && w+e[i]<=q){
                ++ans;
                w+=e[i];
            }
        }
        cout<<"Case "<<c<<": "<<ans<<"\n";
    }
}