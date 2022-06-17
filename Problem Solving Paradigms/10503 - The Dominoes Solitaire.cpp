#include <bits/stdc++.h>

using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi pair<int,int>
#define vi vector<int>
#define vpi vector<pair<int,int>>

int n,m;
vpi pieces(14);
vi used(14);
bool sol;
pi L,R;

void rotate(pi &piece){
    swap(piece.first,piece.second);
}

void solve(pi &prev,int pos){
    if(pos>=n){
        sol = prev.second==R.first ? true:sol;
        return;
    }

    int i=0;
    while(i<m && !sol){
        if(!used[i]){
            used[i]=1;
            if(prev.second==pieces[i].first) solve(pieces[i],pos+1);

            rotate(pieces[i]);
            if(prev.second==pieces[i].first) solve(pieces[i],pos+1);
            used[i]=0;
        }
        i++;
    }
}

int main(){
    fastio
    while (cin>>n>>m && n!=0)
    {
        sol=false;
        cin>>L.first>>L.second>>R.first>>R.second;
        for (size_t i = 0; i < m; i++)
        {
            cin>>pieces[i].first>>pieces[i].second;
        }
        solve(L,0);
        cout<<(sol ? "YES":"NO")<<"\n";
        fill(used.begin(),used.end(),0);
    }
}