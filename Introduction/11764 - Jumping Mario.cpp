#include <iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    for (int i = 1; i <= t; i++)
    {
        int n,hjmp=0,lwjmp=0;
        cin>>n;
        int walls[55];
        for (int j = 0; j < n; j++)
        {
            cin>>walls[j];
            if(j>0){
                if(walls[j-1]<walls[j]) ++hjmp;
                else if(walls[j-1]>walls[j]) ++lwjmp;
            }
        }
        cout<<"Case "<<i<<": "<<hjmp<<" "<<lwjmp<<"\n";
    }
    
}