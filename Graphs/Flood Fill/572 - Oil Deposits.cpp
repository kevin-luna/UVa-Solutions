#include <bits/stdc++.h>

using namespace std;

#define vc vector<char>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<vc> graph;
int dc[] = {-1,-1,-1,0,1,1,1,0};
int dr[] = {1,0,-1,-1,-1,0,1,1};
int n,m;

bool isOut(int r,int c){
    return r<0 || r>=n || c<0 || c>=m;
}

int flood_fill(int r,int c,char find,char replace){
    if(isOut(r,c) || graph[r][c]!=find) return 0;

    graph[r][c]=replace;

    for (int i = 0; i < 8; i++)
    {
        flood_fill(r+dr[i],c+dc[i],find,replace);
    }
    
    return 1;
}

int main(){
    fastio
    graph.assign(100,vc(100,0));
    while (cin>>n>>m && m!=0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin>>graph[i][j];
            }
        }
        
        int dep=0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dep+=flood_fill(i,j,'@','*');
            }
            
        }
        cout<<dep<<"\n";
    }
    
}