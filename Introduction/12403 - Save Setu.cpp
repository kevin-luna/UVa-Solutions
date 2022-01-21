#include <iostream>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;
    int a=0,m;
    string s;
    for (int i = 0; i < t; i++)
    {
        cin>>s;
        if(s=="donate"){
            cin>>m;
            a+=m;
        }else cout<<a<<"\n";
    }
    
}