#include <iostream>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;

    for (int i = 1; i <= t; i++)
    {
        string s;
        cin>>s;
        if((s[0]=='o' && s[2]=='e')  || (s[0]=='o' && s[1]=='n') || (s[1]=='n' && s[2]=='e')){
            cout<<"1"<<"\n";
        }else if((s[0]=='t' && s[2]=='o')  || (s[0]=='t' && s[1]=='w') || (s[1]=='w' && s[2]=='o')){
            cout<<"2"<<"\n";
        }else{
            cout<<"3"<<"\n";
        }     
    }
    
}