#include <bits/stdc++.h>

using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vs vector<string>
vs sol;

void solve(vs &words,int wn,int d,string &rule,int c){
    if(c>=rule.size()){
        for (int i = 0; i < rule.size(); i++)
        {
            cout<<sol[i];
        }
        cout<<"\n";
        return;
    }

    if(rule[c]=='#'){
        for (int i = 0; i < words.size(); i++)
        {
            sol[c]=words[i];
            solve(words,i,d,rule,c+1);
        }
    }else{
        for (int i = 0; i <= 9; i++)
        {
            sol[c]=to_string(i);
            solve(words,wn,i,rule,c+1);
        }
    }
}

int main(){
    fastio
    int n;
    vs words;
    while (cin>>n)
    {
        cout<<"--"<<"\n";
        words.assign(n,"");
        for(int i=0;i<n;i++){
            cin>>words[i];
        }
        string rule;
        int r;
        cin>>r;
        for (int i = 0; i < r; i++)
        {
            cin>>rule;
            sol.assign(rule.size(),"");
            solve(words,0,0,rule,0);
        }
    }
}