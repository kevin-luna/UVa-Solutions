#include <iostream>

using namespace std;

int main(){
    int k,n,m;
    while(cin>>k && k!=0){
        cin>>n>>m;
        for (int i = 0; i < k; i++)
        {
            int x,y;
            cin>>x>>y;
            if(x==n || y==m) cout<<"divisa\n";
            else if(x>n && y>m) cout<<"NE\n";
            else if(x>n && y<m) cout<<"SE\n";
            else if(x<n && y>m) cout<<"NO\n";
            else cout<<"SO\n";
        }
    }
}