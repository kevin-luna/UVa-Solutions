#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

char grid[8][8];
int n,m;
const string s = "IEHOVA#";

const int dr[]={0,-1,0};

const int dc[]={-1,0,1};

const string outputs[] = {"left","forth","right"};

bool isValid(int i,int j){
    return i>=0 || i<n || j>=0 || j<m;
}

void solve(int pos,int i,int j){

    if(pos>=s.size()){
        return;
    }

    for (size_t k = 0; k < 3; k++)
    {
        if(isValid(i+dr[k],j+dc[k]) && grid[i+dr[k]][j+dc[k]]==s[pos]){
            if(pos>0) cout<<" ";
            cout<<outputs[k];
            solve(pos+1,i+dr[k],j+dc[k]);
        }
    }
}

int main(){
    fastio
    int t;
    cin>>t;
    for (size_t i = 0; i < t; i++)
    {
        cin>>n>>m;
        pair<int,int> start;
        memset(grid,0,sizeof(grid));
        for(size_t j=0;j<n;j++){
            for(size_t k=0;k<m;k++){
                cin>>grid[j][k];
                if(grid[j][k]=='@')start={j,k};
            }
        }
        solve(0,start.first,start.second);
        cout<<"\n";
    }
}