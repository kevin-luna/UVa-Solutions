#include <iostream>
#include <cstring>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;

    for (int i = 1; i <=t; i++)
    {
        
        int n,m;
        cin>>n>>m;
        
        int graph[10][30];
        memset(graph,0,sizeof(graph));

        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cin>>graph[j][k];
            }
        }

        int edges[10][10];
        memset(edges,0,sizeof(edges));
        bool directed=true;
        for(int j=0;j<m;j++){
            int incidences=0;
            int firstVertex,lastVertex;
            for(int k=0;k<n;k++){


                if(graph[k][j]==1){
                    if(incidences==0){
                        firstVertex=k;
                    }else{
                        lastVertex=k;
                    }
                    incidences+=1;
                }
            }

            if(incidences!=2){
                directed=false;
            }else{
                if(edges[firstVertex][lastVertex]==1 || edges[lastVertex][firstVertex]==1){
                    directed=false;
                }
                edges[firstVertex][lastVertex]=1;
                edges[lastVertex][firstVertex]=1;
            }
        }
        
        cout<<( (directed ) ? "Yes" : "No")<<"\n";
    }
    
}