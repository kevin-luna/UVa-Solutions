#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
    fastio
    int T,D,Q,q,cnt,k=1;
    string M[10005],ans;
    int L[10005],H[10005];
    cin>>T;
    for (size_t c = 0; c < T; c++)
    {
        if(k++>1)cout<<"\n";
        cin>>D;
        for (size_t i = 0; i < D; i++)
        {
            cin>>M[i]>>L[i]>>H[i];
        }
        cin>>Q;
        for (size_t i = 0; i < Q; i++)
        {
            cin>>q;
            cnt=0;
            for (size_t i = 0; i < D; i++)
            {
                if(q>=L[i] && q<=H[i]){++cnt;ans=M[i];}
                if(cnt>1)break;
            }
            cout<<(cnt==1?ans:"UNDETERMINED")<<"\n";
        }
    }
}