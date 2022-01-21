#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,m;
    while (cin>>m>>n)
    {
        vector<vector<int>> matrix(n,vector<int>(m,0));
        vector<int> non_zero(10000,0);
        for(int i=0;i<m;i++){
            int r;
            cin>>r;
            if(r!=0){
                int columnas[10000];
                for(int j=0;j<r;j++){
                    cin>>columnas[j];
                }
                for(int k=0;k<r;k++){
                    cin>>matrix[columnas[k]-1][i];
                    ++non_zero[columnas[k]-1];
                }
            }
        }

        cout<<n<<" "<<m<<"\n";//dimensiones de la matriz
        for(int i=0;i<n;i++){
            cout<<non_zero[i];//numero de elementos diferentes de cero
            for(int j=0;j<m;j++){
                if(matrix[i][j]!=0){
                    cout<<" "<<j+1;
                }
            }
            cout<<"\n";
            for(int k=0;k<m;k++){
                if(matrix[i][k]!=0){
                    cout<<matrix[i][k];
                    if(k<m-1){
                        cout<<" ";
                    }
                }
            }
            cout<<"\n";
        }

    }
    
}