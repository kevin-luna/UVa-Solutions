#include <iostream>

using namespace std;

int main(){

    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin>>n;
        int s,min=99,max=0;
        for (int j = 0; j < n; j++)
        {
            cin>>s;
            if(s<min) min=s;

            if(s>max) max=s;
        }
        
        cout<<2*max-2*min<<"\n";
    }
    
}