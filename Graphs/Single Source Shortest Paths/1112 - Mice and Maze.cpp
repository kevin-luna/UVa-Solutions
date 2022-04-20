#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int,int>
#define vpi vector<pi>
#define vvpi vector<vpi>

vvpi graph;

int realCell(int v){
    return v-1;
}

void dijkstra(int start,int destine,priority_queue<pi,vpi,greater<pi>> &nextNodes,vi &distances){
    distances[start]=0;
    nextNodes.push({0,start});

    while (!nextNodes.empty())
    {
        pi currentNode = nextNodes.top();
        nextNodes.pop();
        int distance = currentNode.first,node=currentNode.second;
        if(distance>distances[node]) continue;
        for (int i = 0; i < graph[node].size(); i++)
        {
            pi neighbour = graph[node][i];
            if(distances[currentNode.second]+neighbour.first<distances[neighbour.second]){
                distances[neighbour.second]=distances[currentNode.second]+neighbour.first;
                nextNodes.push({distances[neighbour.second],neighbour.second});
            }
        }
        
    }
    
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int cases;
    cin>>cases;
    int n,e,t;
    for(int c=1;c<=cases;c++)
    {
        if(c>1) cout<<"\n";

        cin>>n>>e>>t;
        graph.assign(105,vpi(0));
        int m;
        cin>>m;
        int a;
        pi conn;
        for (int i = 0; i < m; i++)
        {
            cin>>a>>conn.second>>conn.first;
            conn.second=realCell(conn.second);
            graph[realCell(a)].push_back(conn);
        }

        int mices=0;
        priority_queue<pi,vpi,greater<pi>> nextNodes;
        for (int j = 0; j < n; j++)
        {
            vi distances(105,t+5);
            dijkstra(j,realCell(e),nextNodes,distances);
            if(distances[realCell(e)]<=t) mices++;
        }
        
        cout<<mices<<"\n";  
    }

}