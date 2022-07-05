#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n,m;
int vessels[1000];

bool simula(ll x){
    int cc=1,i=0;
    ll ac=0;
    while(i<n)
    {
        if(ac+vessels[i]<=x){
            ac+=vessels[i];
            ++i;
        }else{
            ac=0;
            ++cc;
            if(cc>m)return false;
        }
    }
    return true;
}

int main(){
    while (cin>>n>>m)
    {
        int L=1,R=0;
        for(int i=0;i<n;i++){
            cin>>vessels[i];
            R+=vessels[i];
        }
        ll sol=0;
        ++R;//wtf?
        while (L!=R)
        {
            ll mid = (L+R)/2;
            if(simula(mid)){
                sol = mid;
                R=mid;
            }
            else L=mid+1;
        }
        cout<<sol<<"\n";
    }
}