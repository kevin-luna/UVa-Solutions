#include <bits/stdc++.h>

using namespace std;

#define pi pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vpi vector<pi>
#define vvpi vector<vpi>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vvpi graph;
vi visited;
priority_queue<pi> nextNodes;

void process(int v){
    visited[v]=1;
    for (int i = 0; i < graph[v].size(); i++)
    {
        pi current = graph[v][i];
        if(!visited[current.second])
            nextNodes.push({-current.first,-current.second});
    }
}

int main(){
    fastio
    int n,t=0;
    while (cin>>n)
    {
        if(t++>0)cout<<"\n";
        
        graph.assign(n+5,vpi());
        int s,e,w;

        int Tcost=0;
        for (int i = 0; i < n-1; i++)
        {
            cin>>s>>e>>w;
            Tcost+=w;
        }
        int k;
        cin>>k;

        for (int j = 0; j < k; j++)
        {
            cin>>s>>e>>w;
            graph[s].push_back(make_pair(w,e));
            graph[e].push_back(make_pair(w,s));   
        }

        int m;
        cin>>m;
        for (int i = 0; i < m; i++)
        {
            cin>>s>>e>>w;
            graph[s].push_back(make_pair(w,e));
            graph[e].push_back(make_pair(w,s)); 
        }

        visited.assign(n+5,0);
        process(1);
        int mst_cost=0;
        while (!nextNodes.empty())
        {
            pi front = nextNodes.top();nextNodes.pop();
            int weight = -front.first,vertex=-front.second;
            if(!visited[vertex]){
                mst_cost+=weight;
                process(vertex);
            }
        }
        cout<<Tcost<<"\n"<<mst_cost<<"\n";
        
    }
    
}