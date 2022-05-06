#include <bits/stdc++.h>

using namespace std;

#define edge pair<int,string>
#define msve map<string,vector<edge>>
#define ms map<string,int>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

msve graph;
ms visited;
priority_queue<edge> nextNodes;

void process(string v){
    visited[v]=1;
    for (auto &e : graph[v])
    {
        if(!visited[e.second])
            nextNodes.push({-e.first,e.second});
    }
    
}

int main(){
    fastio
    int t;
    cin>>t;
    for (int c = 1; c <= t; c++)
    {
        if(c>1)cout<<"\n";
        int m,n;
        cin>>m>>n;
        string start;
        for (int i = 0; i < n; i++)
        {
            string s,e;int c;
            cin>>s>>e>>c;
            graph[s].push_back({c,e});
            graph[e].push_back({c,s});
            if(i==0) start=s;
        }

        for (auto &v : graph)
        {
            visited[v.first]=0;
        }
        
        process(start);
        int mstCost=0;
        while (!nextNodes.empty())
        {
            edge curr = nextNodes.top();nextNodes.pop();
            int cost = -curr.first;string node = curr.second;
            if(!visited[node]){
                mstCost+=cost;
                process(node);
            }
        }
        
        cout<<mstCost<<"\n";
        graph.clear();
    }
    
}