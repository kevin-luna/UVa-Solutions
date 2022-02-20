#include <iostream>
#include <cstring>

using namespace std;

char board[11][11];
int visited[11][11];
int steps;
int rows, columns, entry;

void dfs(int r,int c){
    if(r<0 || r>=rows || c<0 || c>=columns){
        cout<<steps<<" step(s) to exit\n";
        return;
    }

    if(visited[r][c]!=0){
        cout<<visited[r][c]-1<<" step(s) before a loop of "<<steps-visited[r][c]+1<<" step(s)\n";
        return;
    }
    
    ++steps;
    visited[r][c]=steps;

    int nr=r,nc=c;
    if(board[r][c]=='N') --nr;
    else if(board[r][c]=='S') ++nr;
    else if(board[r][c]=='E') ++nc;
    else if(board[r][c]=='W') --nc;

    dfs(nr,nc);
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    while (cin>>rows>>columns>>entry && rows!=0 && columns!=0 && entry!=0)
    {
        entry-=1;
        steps=0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                cin>>board[i][j];
            }
        }
        memset(visited,0,sizeof(visited));
        dfs(0,entry);
    }
    
}