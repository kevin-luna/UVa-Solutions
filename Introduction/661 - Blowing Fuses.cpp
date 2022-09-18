#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
    fastio
    int n,m,c,cons[25],sq=1;
    bool state[25],ans;
    while (cin>>n>>m>>c)
    {
        if(n==0 && m==0 && c==0)break;
        memset(state,0,sizeof(state));
        for (size_t i = 1; i <= n; i++)
        {
            cin>>cons[i];
        }
        int tmp,maxc=0,currc=0;
        ans=true;
        for (size_t i = 0; i < m; i++)
        {
            cin>>tmp;
            currc+= (state[tmp]) ? -cons[tmp]:cons[tmp];
            if(currc>c){
                ans=false;
            }
            state[tmp]=!state[tmp];
            maxc=max(maxc,currc);
        }
        cout<<"Sequence "<<sq++<<"\n";
        if(!ans)cout<<"Fuse was blown.";
        else cout<<"Fuse was not blown.\nMaximal power consumption was "<<maxc<<" amperes.";
        cout<<"\n\n";
    }
}