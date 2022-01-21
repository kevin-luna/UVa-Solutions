#include <iostream>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;
    for (int i = 1; i <=t; i++)
    {
        int l,w,h;
        cin>>l>>w>>h;
        cout<<"Case "<<i<<": ";
        if(l<=20 && w<=20 && h<=20){
            cout<<"good\n";
        }else{
            cout<<"bad\n";
        }

    }
    
}