#include <iostream>

using namespace std;

char image[30][30];

const int dr[] = {1,1,0,-1,-1,-1,0,1};
const int dc[] = {0,1,1,1,0,-1,-1,-1};

int R,C;
int flood_fill(int r,int c,int find,int replace){
    if(r<0 || r>=R || c<0 || c>=C){
        return 0;
    }

    if(image[r][c]!=find) return 0;

    int area = 1;
    image[r][c]=replace;

    for (int i = 0; i < 8; i++)
    {
        area += flood_fill(r+dr[i],c+dc[i],find,replace);
    }
    
    return area;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n,t=1;
    bool all_eagles=true,all_zeros=true;
    while (cin>>n)
    {
        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){
                cin>>image[i][j];
                if(image[i][j]=='0') all_eagles=false;
                if(image[i][j]=='1') all_zeros=false;
            }
        }

        if(all_eagles){
            cout<<"Image number "<<t++<<" contains 1 war eagles.\n";
            continue;
        }else if(all_zeros){
            cout<<"Image number "<<t++<<" contains 0 war eagles.\n";
            continue;
        }

        R=n;
        C=n;
        int A=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(flood_fill(i,j,'1','A')>0) A++;
            }
            
        }
        cout<<"Image number "<<t++<<" contains "<<A<<" war eagles.\n";
    }
    
}