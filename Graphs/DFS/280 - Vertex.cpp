#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> grafo;
vector<int> visited;
int nv;

void dfs(int v){
    for (int i = 0; i < grafo[v].size(); i++)
    {
        if(visited[grafo[v][i]]==0){
            visited[grafo[v][i]]=1;
            ++nv;
            dfs(grafo[v][i]);
        }
    }
    
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    while (cin>>n && n!=0)
    {
        int sv;
        grafo.assign(n,vector<int>());
            while(cin>>sv && sv!=0){

                int e;
                while (cin>>e && e!=0)
                {
                    grafo[sv-1].push_back(e-1);
                }
            }

        int inv,v;
        cin>>inv;
        for (int j = 0; j < inv; j++)
        {
            nv=0;
            visited.assign(n,0);
            cin>>v;
            dfs(v-1);
            cout<<n-nv;
            for (int k = 0; k < visited.size(); k++)
            {
                if(visited[k]==0)
                cout<<" "<<k+1;
            }
            cout<<"\n";
        }
    }
    
}