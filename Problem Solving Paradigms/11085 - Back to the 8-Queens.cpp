#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
int col[8],cnt=0,ans[92][8];
bool check(int r,int c){
    if(c==0)return 1;
    for(int prev=0;prev<c;prev++){
        if(col[prev]==r || abs(c-prev)==abs(r-col[prev]))return 0;
    }
    return 1;
}
void backtrack(int c){
    if(c==8 && cnt<=91){
        for(int i=0;i<8;i++){
            ans[cnt][i]=col[i];
        }
        cnt++;
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
    backtrack(0);
    int t=1,x[8];
    while(cin>>x[0]){
        for(int i=1;i<8;i++)cin>>x[i];
        int mn=1e9;
        for(int i=0;i<92;i++){
            int mv=0;
            for(int j=0;j<8;j++){
                mv+=(ans[i][j]+1!=x[j]);
            }
            mn=min(mv,mn);
        }
        cout<<"Case "<<t++<<": "<<mn<<"\n";
    }
}