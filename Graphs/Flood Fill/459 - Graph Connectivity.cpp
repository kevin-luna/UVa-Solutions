#include <iostream>
#include <cstring>

using namespace std;

int graph[27][27];
int visited[27];
int maxNodes;

void dfs(int v){
    visited[v]=1;
    for (int i = 0; i < maxNodes; i++)
    {
        if(graph[v][i] && visited[i]==0){
            dfs(i);
        }
    }
}

int main(){
    int n;
    cin>>n;

    for (int i = 1; i <=n; i++)
    {   
        if(i>1) cout<<"\n";
        char ln;
        cin>>ln;
        cin.ignore();

        maxNodes = int(ln-'A')+1;

        string edge;
        memset(graph,0,sizeof(graph));
        memset(visited,0,sizeof(visited));

        while (getline(cin,edge) && !edge.empty())
        {
            graph[int(edge[0]-'A')][int(edge[1]-'A')]=1;
            graph[int(edge[1]-'A')][int(edge[0]-'A')]=1;
        }

        int subgraphs=0;
        for (int j = 0; j < maxNodes; j++)
        {
            if(visited[j]==0){
                dfs(j);
                subgraphs++;
            }
        }
        cout<<subgraphs<<"\n";
    }
}