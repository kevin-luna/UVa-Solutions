#include <iostream>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t=1;
    string s;
    while (cin>>s && s!="*")
    {
        cout<<"Case "<<t++<<": ";
        if(s=="Hajj") cout<<"Hajj-e-Akbar\n";
        else cout<<"Hajj-e-Asghar\n";
    }
    
}