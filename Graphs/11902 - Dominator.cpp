#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int t,n;
bool graph[105][105],fromzero[105],visited[105];
void dfs(int v,int i,bool *visited){
    if(!visited[v] && v!=i){
        visited[v]=1;
        for (size_t j = 0; j < n; j++)
        {
            if(graph[v][j]==1 && !visited[j])dfs(j,i,visited);
        }
    }
}
void printline(int n){
    cout<<"+";
    for(size_t i=0;i<2*n-1;i++)cout<<"-";
    cout<<"+\n";
}
int main(){
    fastio
    cin>>t;
    for (size_t c = 1; c <= t; c++)
    {
        cin>>n;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                cin>>graph[i][j];
            }
        }
        cout<<"Case "<<c<<":\n";
        memset(fromzero,0,sizeof(fromzero));
        dfs(0,-1,fromzero);
        printline(n);
        for (size_t i = 0; i < n; i++)
        {
            memset(visited,0,sizeof(visited));
            dfs(0,i,visited);
            cout<<"|";
            for (size_t j = 0; j < n; j++)
            {
                cout<<(fromzero[j]&&!visited[j]?"Y|":"N|");
            }
            cout<<"\n";
            printline(n);
        }
    }
}