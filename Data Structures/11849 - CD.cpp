#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
    int n,m;
    map<int,int> jack;
    while(cin>>n>>m && n+m!=0){
        int cat;
        for (int i = 0; i < n; i++)
        {
            cin>>cat;
            jack[cat]++;
        }
        int both=0;
        for (int j = 0; j < m; j++)
        {
            cin>>cat;
            if(jack[cat])both++;
        }
        cout<<both<<"\n";
        jack.clear();
    }
}