#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
int col[8],cnt=0,sol[92][8];
bool check(int r,int c){
    if(c==0)return 1;
    for(int prev=0;prev<c;prev++){
        if(col[prev]==r||abs(c-prev)==abs(col[prev]-r))return 0;
    }
    return 1;
}
void backtrack(int c){
    if(c==8){
        for(int i=0;i<8;i++){
            sol[cnt][i]=col[i];
        }
        ++cnt;
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
    int t;
    cin>>t;
    backtrack(0);
    while(t--){
        int r,c;
        cin>>r>>c;
        --r;--c;
        cout<<"SOLN       COLUMN\n";
        cout<<" #      1 2 3 4 5 6 7 8\n\n";
        int soln=1;
        for(int i=0;i<92;i++){
            if(sol[i][c]==r){
                cout<<right<<setw(2)<<soln++<<"      ";
                for(int j=0;j<8;j++){
                    cout<<(j>0?" ":"")<<sol[i][j]+1;
                }
                cout<<"\n";
            }
        }
        if(t>=1)cout<<"\n";
    }
}