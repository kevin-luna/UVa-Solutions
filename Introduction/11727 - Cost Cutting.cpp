#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;
    for (int i = 1; i <= t; i++)
    {
        int employees[3];
        for (int j = 0; j < 3; j++)
        {
            cin>>employees[j];
        }
        
        sort(employees,employees+3);
        cout<<"Case "<<i<<": "<<employees[1]<<"\n";

    }
    
}