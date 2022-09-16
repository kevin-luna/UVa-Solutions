#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
    fastio
    string s;
    s.reserve(100005);
    list<string> t;
    while(cin>>s){
        bool front=true;
        t.emplace_front("");
        for (auto &c : s)
        {
            if(c=='['){
                front=true;
                t.emplace_front("");
            }
            else if(c==']'){
                front=false;
                t.emplace_back("");
            }else if(front){
                t.front()+=c;
            }else{
                t.back()+=c;
            }
        }
        for(auto &e:t){
            cout<<e;
        }
        cout<<"\n";
        t.clear();
    }
}