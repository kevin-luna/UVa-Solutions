#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vi vector<int>

vi visited;
vector<vi> graph;
int fallen;

void dfs(int v){

    visited[v]=1;
    for (auto &e : graph[v])
    {
        if(!visited[e]){
            dfs(e);
        }
    }
    
}

int main(){
    fastio
    int t;
    cin>>t;
    for (int c = 1; c <= t; c++)
    {
        int n,m,l;
        cin>>n>>m>>l;
        graph.assign(n+1,vi(0));
        for (int i = 0; i < m; i++)
        {
            int x,y;
            cin>>x>>y;
            graph[x].push_back(y);
        }

        int knocked;
        visited.assign(n+1,0);
        for (int j = 1; j <= l; j++)
        {
            cin>>knocked;
            dfs(knocked);
        }

        fallen=0;
        for (auto &e : visited)
        {
            if(e) fallen++;
        }

        cout<<fallen<<"\n";
    }
    
}