#include <iostream>
#include <vector>

using namespace std;

vector<int> fenwickTree;
int n;

int getSum(int index)
{
    int sum = 0; 
    while (index>0)
    {
        sum += fenwickTree[index];
        index -= index & (-index);
    }
    return sum;
}

void updateBIT(int index, int val)
{
    while (index <= n)
    {
        fenwickTree[index] += val;
        index += index & (-index);
    }
}

vector<int> potmeters(200005);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    while (cin>>n && n!=0)
    {
        if(t>1)cout<<"\n";
        cout<<"Case "<<t++<<":\n";
        
        
        fenwickTree.assign(n+1,0);

        for (int i=1; i<=n; i++){
            cin>>potmeters[i];
            updateBIT(i, potmeters[i]);
        }

        string query;
        while (cin>>query)
        {
            if(query=="END") break;
            
            int x,y;
            cin>>x>>y;
            if(query[0]=='S'){
                int dif = y-potmeters[x];
                updateBIT(x,dif);
                potmeters[x]=y;
            }
            else{
                cout<<getSum(y)-getSum(x-1)<<"\n";
            }
        }
    }
}