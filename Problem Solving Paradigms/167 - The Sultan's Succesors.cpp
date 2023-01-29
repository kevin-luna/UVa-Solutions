#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
int solcnt=0,board[8][8], col[8],sol[92][8];
bool check(int r,int c){
    if(c==0)return true;
    for(int prev=0;prev<c;prev++){
        if((col[prev]==r)||abs(c-prev)==abs(r-col[prev]))return false;
    }
    return true;
}
void backtrack(int c){
    if(c==8 && solcnt<92){
        for(int j=0;j<8;j++){
            sol[solcnt][j]=col[j];
        }
        ++solcnt;
        return;
    }
    for(int r=0;r<8;r++){
        if(check(r,c)){
            col[c]=r;
            backtrack(c+1);
        }
    }
}
int main(){
    fastio
    int k;
    memset(sol,-1,sizeof sol);
    memset(col,-1,sizeof col);
    cin>>k;
    backtrack(0);
    while(k--){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cin>>board[i][j];
            }
        }
        int ans=0;
        for(int i=0;i<92;i++){
            int sum=0;
            for(int j=0;j<8;j++){
                sum+=board[j][sol[i][j]];
            }
            ans=max(ans,sum);
        }
        cout<<right<<setw(5)<<ans<<"\n";
    }
}