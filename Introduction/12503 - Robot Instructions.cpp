#include <iostream>
#include <vector>

using namespace std;

int pf=0; string ins;

void exec(string instruction){
    if(instruction=="LEFT") --pf;
    else if(instruction=="RIGHT") ++pf;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin>>n;
        cin.ignore(1);
        vector<string> past;
        int ni;//number of instruction
        for (int j = 0; j < n; j++)
        {
            getline(cin,ins);
            if(ins!="LEFT" && ins!="RIGHT"){
                ni=stoi(ins.substr(7))-1;
                past.push_back(past[ni]);
                exec(past[ni]);
            }else{
                past.push_back(ins);
                exec(ins);
            }
        }
        cout<<pf<<"\n";
        pf=0;
    }
    
}