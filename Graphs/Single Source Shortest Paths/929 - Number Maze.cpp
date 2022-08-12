#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define pip pair<int,pii>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
    fastio
    int mazes;
    cin>>mazes;
    int n,m;
    while (cin>>n>>m)
    {
        vvi maze(n,vi(m));
        vvi dist(n,vi(m,10000));
        dist[0][0]=0;
        priority_queue<pip,vector<pip>,greater<pip>> nodes;
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < m; c++)
            {
                cin>>maze[r][c];
            }
        }
        nodes.push(make_pair(maze[0][0],make_pair(0,0)));
        dist[0][0]=maze[0][0];
        while (!nodes.empty())
        {
            pip front = nodes.top();
            nodes.pop();
            int d = front.first;
            pii v = front.second;
            if(d>dist[v.second][v.first]) continue;
            int dx[] = {0,0,-1,1};
            int dy[] = {-1,1,0,0};
            for (int i = 0; i < 4; i++)
            {
                int x = v.first+dx[i];
                int y = v.second+dy[i];
                if(x<0 || x>=m || y<0 || y>=n) continue;

                int dn = maze[y][x];
                int dc = dist[v.second][v.first];

                if(dist[y][x]==10000 || dc+dn<dist[y][x]){
                    dist[y][x]=dc+dn;
                    nodes.push(make_pair(dist[y][x],make_pair(x,y)));
                }
            }
        }
        cout<<dist[n-1][m-1]<<"\n";
    }
}