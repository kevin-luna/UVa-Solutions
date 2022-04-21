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
#define INF 100000

vvpi net;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int testcases;
    cin>>testcases;
    priority_queue<pi,vpi,greater<pi>> nextServers;
    for (int cases = 1; cases <= testcases; cases++)
    {
        int n,m,S,T;
        cin>>n>>m>>S>>T;
        net.assign(20005,vpi(0));
        for (int conn = 0; conn < m; conn++)
        {
            int s1,s2,l;
            cin>>s1>>s2>>l;
            net[s1].push_back(make_pair(l,s2));
            net[s2].push_back(make_pair(l,s1));
        }
        
        vi latencies(20005,INF);
        latencies[S]=0;
        nextServers.push(make_pair(0,S));
        while (!nextServers.empty())
        {
            pi currentServer = nextServers.top();
            nextServers.pop();
            int latency = currentServer.first, server=currentServer.second;

            if(latency>latencies[server]) continue;

            for (int j = 0; j < net[server].size(); j++)
            {
                pi neighbour = net[server][j];
                if(latencies[currentServer.second]+neighbour.first<latencies[neighbour.second]){
                    latencies[neighbour.second]=latencies[currentServer.second]+neighbour.first;
                    nextServers.push(make_pair(latencies[neighbour.second],neighbour.second));
                }
            }
        }

        cout<<"Case #"<<cases<<": ";
        if(latencies[T]==INF)cout<<"unreachable\n";
        else cout<<latencies[T]<<"\n";
    }
    
}