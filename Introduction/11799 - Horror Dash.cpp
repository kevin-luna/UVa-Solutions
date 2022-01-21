#include <iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    for (int i = 1; i <= t; i++)
    {
        int n,v,max=1;
        cin>>n;
        
        for (int j = 0; j < n; j++)
        {
            cin>>v;
            max = (v>max) ? v : max;
        }
        cout<<"Case "<<i<<": "<<max<<"\n";
    }
    
}