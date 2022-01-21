#include <iostream>
#include <vector>
using namespace std;
int n,m,k,v,number;
vector<vector<int>> numbers;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    while (cin>>n>>m)
    {
        numbers.assign(1000000,vector<int>());
        for(int i=0;i<n;i++){
            cin>>number;
            numbers[number].push_back(i+1);
        }

        for(int j=0;j<m;j++){
            cin>>k>>v;
            if(k<=numbers[v].size()){
                cout<<numbers[v][k-1]<<"\n";
            }else{
                cout<<"0\n";
            }
        }
    }

    return 0;
}
