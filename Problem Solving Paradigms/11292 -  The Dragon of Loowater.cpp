#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int heads[20005],knights[20005];
int main(){
    fastio
    int n,m,t=0;
    while (cin>>n>>m && n+m!=0)
    {
            int sum=0;
            for (size_t i = 0; i < n; i++)
            {
                cin>>heads[i];
                sum+=heads[i];
            }
            for (size_t i = 0; i < m; i++)
            {
                cin>>knights[i];
            }
        if(m<n){
            cout<<"Loowater is doomed!\n";
        }else{
            sort(heads,heads+n);
            sort(knights,knights+m);
            int head=0,coins=0;
            for (size_t i = 0; i < m && head<n; i++)
            {
                if(knights[i]>=heads[head]){
                    coins+=knights[i];
                    head++;
                }
            }
            if(coins>=sum && head==n){
                cout<<coins<<"\n";
            }else{
                cout<<"Loowater is doomed!\n";
            }
        }
    }
}