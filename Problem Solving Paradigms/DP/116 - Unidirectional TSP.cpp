#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int m,n;
ll grid[15][105],memo[15][105],path[15][105];
ll dp(int r,int c){
    if(c>n)return 0;
    ll &ans = memo[r][c];
    if(ans!=INT_MAX) return memo[r][c];
    int s[] = {r-1,r,r+1};
    if(r==1)s[0]=m;
    if(r==m)s[2]=1;
    for(int i=0;i<3;i++){
        int tmp=grid[r][c]+dp(s[i],c+1);
        if(ans>tmp || ans==tmp && path[r][c]>s[i]){
            ans=tmp;
            path[r][c]=s[i];
        }
    }
    return ans;
}
int main(){
    while(cin>>m>>n){
        for(int r=1;r<=m;r++)
            for(int c=1;c<=n;c++){
                cin>>grid[r][c];
                memo[r][c]=INT_MAX;
            }
        int best=INT_MAX,start=1;
        for(int i=1;i<=m;i++){
            dp(i,1);
            if(best>memo[i][1]){
                best=memo[i][1];
                start=i;
            }
        }
        for(int i=1;i<=n;i++){
            cout<<(i>1?" ":"")<<start;
            start=path[start][i];
        }
        cout<<"\n"<<best<<"\n";
    }
}