#include <iostream>

using namespace std;

char board[205][205];

const int dr[] = {-1,-1,0,0,1,1};
const int dc[] = {-1,0,-1,1,0,1};

int R,C;
bool reach_start,reach_end;
void flood_fill(int r,int c,char find,char replace){

    if(r<0 || r>=R || c<0 || c>=C){
        return;
    }

    if(board[r][c]!=find) return;

    board[r][c]=replace;


    if(find=='b'){
        if(r==0){
            reach_start=true;
        }else if(r==R-1){
            reach_end=true;
        }
    }
    else if(find=='w'){
        if(c==0){
            reach_start=true;
        }else if(c==C-1){
            reach_end=true;
        }
    }

    for (int i = 0; i < 6; i++)
    {
        flood_fill(r+dr[i],c+dc[i],find,replace);
    }
    
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n,t=1;
    while (cin>>n && n!=0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin>>board[i][j];
            }
        }
        R=n;
        C=n;
        char winner='#';
        for (int i = 0; i < n; i++)
        {
            if(winner!='#') break;

            for (int j = 0; j < n; j++)
            {
                reach_start=false;
                reach_end=false;
                if(board[i][j]=='b'){
                    flood_fill(i,j,'b','x');
                    if(reach_start && reach_end){
                        winner='B';
                        break;
                    }
                }
                else if(board[i][j]=='w'){
                    flood_fill(i,j,'w','x');
                    if(reach_start && reach_end){
                        winner='W';
                        break;
                    }
                    
                }
            }
        }
        cout<<t++<<" "<<winner<<"\n";
    }
    
}