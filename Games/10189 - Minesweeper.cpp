#include <iostream>

using namespace std;

int n,m;
string square[105];

void checkAdjacency(int x,int y){
    if(square[y][x]=='*') return;

    int around[8][2] = {
        // Up
        {x-1,y+1},
        {x,y+1},
        {x+1,y+1},
        // Both sides
        {x-1,y},
        {x+1,y},
        // Down
        {x-1,y-1},
        {x,y-1},
        {x+1,y-1}
    };
    int adj=0;
    for (int i = 0; i < 8; i++)
    {
        if(around[i][0]>=0 && around[i][0]<m && around[i][1]>=0 && around[i][1]<n && square[around[i][1]][around[i][0]]=='*')
        adj++;
    }
    square[y][x]=adj+48;
}

int main(){
    int field = 1;
    while (cin>>n>>m && n!=0 && m!=0)
    {
        if(field>1) cout<<"\n";
        
        for(int i=0;i<n;i++){
            cin>>square[i];
        }
        cout<<"Field #"<<field++<<":\n";
        for (int j = 0; j < n; j++)
        {
            for(int k=0;k<m;k++){
                checkAdjacency(k,j);
            }
                cout<<square[j]<<"\n";
        }
        
    }
    
}