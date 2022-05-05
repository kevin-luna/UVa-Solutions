#include <bits/stdc++.h>

using namespace std;

#define pdi pair<double,int>
#define pd pair<double,double>
#define vi vector<int>
#define vpdi vector<pdi>
#define vpd vector<pd>
#define vvpdi vector<vpdi>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

double dist(pd p1,pd p2){
    double dx=p2.first-p1.first,dy=p2.second-p1.second;
    return sqrt(dx*dx+dy*dy);
}

vpd coord;
vvpdi graph;
priority_queue<pdi> nextNodes;
vi visited;

void process(int v){
    visited[v]=1;
    for (int i = 0; i < graph[v].size(); i++)
    {
        auto current = graph[v][i];
        if(!visited[current.second])
            nextNodes.push({-current.first,-current.second});
    }
    
}

int main(){
    fastio
    int n,t;
    cin>>t;
    for (int c = 1; c <= t; c++)
    {
        if(c>1)cout<<"\n";
        cin>>n;
        coord.assign(n,{0,0});
        double x,y;
        for (int i = 0; i < n; i++)
        {
            cin>>x>>y;
            coord[i]={x,y};
        }
        graph.assign(n,vpdi(0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(j!=i){
                    float d = dist(coord[i],coord[j]);
                    graph[i].push_back({d,j});
                }
            }
        }
        visited.assign(n,0);
        process(0);
        double mstCost = 0;
        while (!nextNodes.empty())
        {
            auto curr = nextNodes.top();nextNodes.pop();
            double w = -curr.first;int v = -curr.second;
            if(!visited[v]){
                mstCost+=w;
                process(v);
            }
        }
        cout<<fixed<<setprecision(2)<<mstCost<<"\n";
    }
}