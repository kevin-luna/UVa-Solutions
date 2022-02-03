#include <iostream>
#include <vector>

using namespace std;

vector<string> grid;
vector<string> aux;

const int dr[] = {1,1,0,-1,-1,-1,0,1};
const int dc[] = {0,1,1,1,0,-1,-1,-1};

int R,C;
int flood_fill(int r,int c,int find,int replace){
    if(r<0 || r>=R || c<0 || c>=C){
        return 0;
    }

    if(aux[r][c]!=find) return 0;

    int area = 1;
    aux[r][c]=replace;

    for (int i = 0; i < 8; i++)
    {
        area += flood_fill(r+dr[i],c+dc[i],find,replace);
    }
    
    return area;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;
    string tmp;
    bool final=false;
    while (cin>>tmp)
    {
        
        if(tmp[0]=='L' || tmp[0]=='W'){
            if(final){
                cout<<"\n";
                grid.clear();
            }
            final=false;
            grid.push_back(tmp);
        }else{
            int row,col;
            row=stoi(tmp);
            cin>>tmp;
            col=stoi(tmp);
            R=grid.size();
            C=grid[0].size();

            aux = grid;
            cout<<flood_fill(row-1,col-1,'W','L')<<"\n";

            final=true;
        }
    }
    
}
