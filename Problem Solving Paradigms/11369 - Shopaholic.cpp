#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
    fastio
    int t;
    cin>>t;
    int n,prices[20005];
    for (size_t i = 0; i < t; i++)
    {
        cin>>n;
        for (size_t j = 0; j < n; j++)
        {
            cin>>prices[j];
        }
        sort(prices,prices+n,greater<int>());
        int d=0;
        for (size_t i = 2;i<n; i+=3)
        {
            d+=prices[i];
        }
        cout<<d<<"\n";
    }
}