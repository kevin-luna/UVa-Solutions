#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef pair<int,int> pii;
int main(){
    fastio
    string s;
    int q,p,k;
    int querys[3005];
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    while (cin>>s)
    {
        if(s=="#")break;
        cin>>q>>p;
        querys[q]=p;
        pq.push({p,q});
    }
    cin>>k;
    for (size_t i = 0; i < k; i++)
    {
        q=pq.top().second;
        p=pq.top().first;
        cout<<q<<"\n";
        pq.pop();
        pq.push({p+querys[q],q});
    }
}