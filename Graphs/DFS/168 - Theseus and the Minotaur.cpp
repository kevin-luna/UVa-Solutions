#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > graph;
vector<int> candles;
int counter=0;

void dfs(int v,int t,int k){
    counter++;
    for (int i = 0; i < graph[v].size(); i++)
    {
        int current_edge = graph[v][i];

        if(counter==k){

            candles[v]=1;
        }

        if(current_edge!=t && candles[current_edge] != 1){
            if(counter==k){
                counter=0;
                cout<<char(v+65)<<" ";
            }
            return dfs(current_edge,v,k);
        }
    }
    cout<<"/"<<char(v+65)<<"\n";
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string line;

    while (cin>>line && line!="#")
    {
        graph.assign(26,vector<int>(0,0));
        candles.assign(26,0);
        char t,m; int k;
        cin>>m>>t>>k;
        counter=0;
        int current_node=-1;
        for (int i = 0; i < line.size(); i++)
        {
            if(line[i]==':'){
                current_node= line[i-1]-65;
            }else if(current_node>=0 && line[i]>=65 && line[i]<=90 && line[i-1]!=';'){
                graph[current_node].push_back(line[i]-65);
            }else{
                continue;
            }
        }
        m-=65;
        t-=65;
        dfs((int)m,(int)t,k);
    }
    
}