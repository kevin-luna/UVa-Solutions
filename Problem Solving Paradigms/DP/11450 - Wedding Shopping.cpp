#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int t,m,c,k;
int garments[25][25],memo[30][205];
int dp(int g,int b){
    if(b<0)return -10000;
    if(g==c)return m-b;
    if(memo[g][b]!=-1)return memo[g][b];
    int ans=-1;
    for(int i=1;i<=garments[g][0];i++){
        ans=max(ans,dp(g+1,b-garments[g][i])); 
    }
    return memo[g][b]=ans;
}
int main(){
    fastio
    cin>>t;
    while(t--){
        cin>>m>>c;
        for(int i=0;i<c;i++){
            cin>>garments[i][0];
            for(int j=1;j<=garments[i][0];j++)
                cin>>garments[i][j];
        }
        memset(memo,-1,sizeof memo);
        int ans = dp(0,m);
        if(ans<0)cout<<"no solution\n";
        else cout<<ans<<"\n";
    }
}