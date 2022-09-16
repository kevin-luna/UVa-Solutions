#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
    fastio
    int n,c=1;
    pair<int,int> soldiers[1005];
    while (cin>>n && n!=0)
    {
        for (size_t i = 0; i < n; i++)
        {
            cin>>soldiers[i].second>>soldiers[i].first;
        }
        sort(soldiers,soldiers+n,greater<pair<int,int>>());
        int last=0,time=0;
        for (size_t i = 0; i < n; i++)
        {
            last+=soldiers[i].second;
            time=max(last+soldiers[i].first,time);
        }
        cout<<"Case "<<c++<<": "<<time<<"\n";
    }
}