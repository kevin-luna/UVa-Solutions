#include <bits/stdc++.h>

using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int t,n;
int rungs[100000];
bool simula(int k){
    int height=0;
    for (size_t i = 0; i < n; i++)
    {
        int d = rungs[i]-height;
        if(k<d) return false;
        if(d==k) --k;
        height=rungs[i];
    }
    return true;
}

int main(){
    fastio
    cin>>t;
    for (int i = 1; i <=t; i++)
    {
        cin>>n;
        for (size_t j = 0; j < n; j++)
        {
            cin>>rungs[j];
        }
        int L=1,R=10000000;
        while(L!=R){
            int mid = (L+R)/2;
            if(simula(mid)){
                R=mid;
            }else{
                L=mid+1;
            }
        }
        cout<<"Case "<<i<<": "<<L<<"\n";
    }
}