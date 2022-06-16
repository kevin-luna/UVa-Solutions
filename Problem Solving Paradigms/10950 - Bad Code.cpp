#include <bits/stdc++.h>

using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vc vector<char>

int solc;

void removeExtraZeros(string &s){
    for (size_t i = 0; i < s.size(); i++)
    {
        if(s[i]=='0' && i+1<s.size() && s[i+1]=='0'){
            s.erase(i,1);
            --i;
        }
    }
}

void solve(string solenc,string &encs,string sol,map<char,string> &codes){
    if(solc>=100) return;

    if(solenc.size()>=encs.size()){
        if(solenc==encs ){
            cout<<sol<<"\n";
            solc++;
        }
        return;
    }

    int start,dif;
    for (auto e:codes)
    {   
        string stcpy=solenc+e.second;
        start=solenc.size();
        dif=stcpy.size()-solenc.size();
        if(stcpy.size()<=encs.size()){
            if(stcpy.substr(start,dif)==encs.substr(start,dif)) solve(stcpy,encs,sol+e.first,codes);
        }

        dif+=1;
        stcpy=solenc+'0'+e.second;
        if(stcpy.size()<=encs.size()){
            if(stcpy.substr(start,dif)==encs.substr(start,dif)) solve(stcpy,encs,sol+e.first,codes);
        }
    }
}

int main(){
    fastio
    int n;
    map<char,string> codes;
    int t=1;
    while (cin>>n && n!=0)
    {
        solc=0;
        for (size_t i = 0; i < n; i++)
        {
            char c;string id;
            cin>>c>>id;
            codes[c]=id;
        }
        string encs,solenc="",sol="";
        cin>>encs;
        cout<<"Case #"<<t++<<"\n";
        removeExtraZeros(encs);
        solve(solenc,encs,sol,codes);
        cout<<"\n";
        codes.clear();
    }
}