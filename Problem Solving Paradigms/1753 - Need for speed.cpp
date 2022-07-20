#include <bits/stdc++.h>

using namespace std;
#define ld long double
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ld n,t;
ld d[1005],s[1005];

bool test(ld c){
    ld totalt=0.0;
    for (size_t i = 0; i < n; i++)
    {
        if(!(s[i]+c > 0.0))return false;
        totalt+=d[i]/(s[i]+c);
    }
    return totalt<t;
}

int main(){
    fastio
    while(cin>>n>>t){
        for (size_t i = 0; i < n; i++)
        {
            cin>>d[i]>>s[i];
        }
        cout<<setprecision(9)<<fixed;
        ld L=-1000.0,R=1001005.0,mid=0.0;
        while(fabs(L-R)>1e-7){
            mid=L+fabs(L-R)/2.0;
            if(test(mid))R=mid;
            else L=mid;
        }
        cout<<L<<"\n";
    }
}