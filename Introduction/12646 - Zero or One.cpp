#include <iostream>

using namespace std;

int main(){
    int a,b,c;
    while (cin>>a>>b>>c)
    {
        if(a==b && b!=c) cout<<"C\n";
        else if(a==c && c!=b) cout<<"B\n";
        else if(b==c && c!=a) cout<<"A\n";
        else cout<<"*\n";
    }
    
}