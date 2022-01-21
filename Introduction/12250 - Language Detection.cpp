#include <iostream>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    string s,lang;
    int t=1;
    while (cin>>s && s!="#")
    {
        if(s=="HELLO"){
            lang="ENGLISH";
        }else if(s=="HOLA"){
            lang="SPANISH";
        }else if(s=="HALLO"){
            lang="GERMAN";
        }else if(s=="BONJOUR"){
            lang="FRENCH";
        }else if(s=="CIAO"){
            lang="ITALIAN";
        }else if(s=="ZDRAVSTVUJTE"){
            lang="RUSSIAN";
        }else{
            lang="UNKNOWN";
        }
        cout<<"Case "<<t++<<": "<<lang<<"\n";
    }
    
}