#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
map<int,vector<string>> cache;

string insertZeros(int n){
    string st;
    for (int i = 1; i <= n; i++)
    {
        st+='0';
    }
    return st;
}

void genNumbers(int d){
    int mx=pow(10,d),mod=pow(10,d/2);
    for (ll i = 0; i < mx; i++)
    {
        ll right = i%mod,left=(i/mod)%mod;
        if((left+right)*(left+right)==i){
            string number=to_string(i);
            cache[d].push_back(insertZeros(d-number.length())+number);
        }
    }
}

int main(){
    fastio
    int digits;
    genNumbers(2);
    genNumbers(4);
    genNumbers(6);
    genNumbers(8);
    while (cin>>digits)
    {
        for (auto &e : cache[digits])
        {
            cout<<e<<"\n";
        }
    }
    
}