#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> visited;
vector<int> vertices;

void dfs(int v){
    visited[v]=1;
    for (int i = 0; i < graph[v].size(); i++)
    {
        if(visited[graph[v][i]]==0){
            dfs(graph[v][i]);
        }
    }
    
}

int main(){
    int t;
    cin>>t;
    for(int test=1;test<=t;test++)
    {
        graph.assign(26,vector<int>(0,0));
        vertices.assign(26,0);
        visited.assign(26,0);
        string edge;
        while (cin>>edge && edge[0]!='*')
        {
            int v = int(edge[1]-65);
            int e = int(edge[3]-65);

            graph[v].push_back(e);
            graph[e].push_back(v);
        }
        
        string points;
        cin>>points;

        for (int i = 0; i < points.size(); i++)
        {
            if(points[i]!=','){
                vertices[int(points[i]-65)]=1;
            }
        }
        
        int accorn=0;
        for (int j = 0; j < 26; j++)
        {
            if(vertices[j]==1 && graph[j].size()<1){
                ++accorn;
            }
        }
        int trees=0;
        for (int k = 0; k < 26; k++)
        {
            if(vertices[k]==1 && graph[k].size()>0){
                if(visited[k]==0){
                    ++trees;
                    dfs(k);
                }
            }

        }
        cout<<"There are "<<trees<<" tree(s) and "<<accorn<<" acorn(s).\n";
    }
    
}