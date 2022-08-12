#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool covered(pii i,int p){
    return i.first<=p && i.second>=p;
}
bool inside(pii i,pii j){
    return i.first<=j.first && i.second>=j.second;
}
int main(){
    fastio
    int t,m;
    cin>>t;
    cin.ignore();
    pii pairs[100005],ans[100005];
    for (size_t c = 1; c <= t; c++)
    {
        cin>>m;
        int L=0,R=0,n=0;
        while(cin>>L>>R){
            if(L==0 && R==0)break;
            pairs[n].first=L;
            pairs[n].second=R;
            ++n;
        }
        sort(pairs,pairs+n);
        int left=0,right=0,j=0;
        for (size_t i = 0; i < n; i++)
        {
            if(pairs[i].second<left || inside({left,right},pairs[i]))continue;
            if(right>=m)break;
            if(covered(pairs[i],left)){
                if(pairs[i].second>right){
                    ans[j]=pairs[i];
                    right=ans[j].second;
                }
            }else{
                if(covered(pairs[i],right)){
                    left=right;
                    ++j;
                    if(pairs[i].second>right){
                        ans[j]=pairs[i];
                        right=ans[j].second;
                    }
                }else{
                    break;
                }
            }
        }
        ++j;
        if(right<m){
            cout<<"0\n";
        }
        else{
            cout<<j<<"\n";
            for (size_t i = 0; i < j; i++)
            {
                cout<<ans[i].first<<" "<<ans[i].second<<"\n";
            } 
        }
        cout<<"\n";
    }
}