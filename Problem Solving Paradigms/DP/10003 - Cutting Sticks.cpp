#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int l,n,cuts[55],memo[55][55];
int dp(int left,int right){
    int &ans=memo[left][right];
    if(right-left==1)return ans=0;
    if(ans!=-1)return ans;
    ans=1e6;
    for(int j=left+1;j<right;j++){
        ans=min(ans,dp(left,j)+dp(j,right)+cuts[right]-cuts[left]);
    }
    return ans;
}
int main(){
    fastio
    while (cin>>l)
    {
        if(l==0)break;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>cuts[i];
        cuts[0]=0,cuts[n+1]=l;
        memset(memo,-1,sizeof memo);
        cout<<"The minimum cutting is "<<dp(0,n+1)<<".\n";
    }
}