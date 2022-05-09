#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int cycle_length(int n){
    int calls=1;
    while (n!=1)
    {
        if(n%2){
            n = 3*n+1;
        }
        else{
            n/=2;
        }
            calls++;
    }
    return calls;
}

int main(){
    
    int i,j,oi,oj;
    while (cin>>i>>j)
    {
        oi=i,oj=j;
        if(i>j) swap(i,j);
        int max=0;
        for (int v = i; v <= j; v++)
        {
            int tmp = cycle_length(v);
            max = tmp>max ? tmp:max;
        }
        cout<<oi<<" "<<oj<<" "<<max<<"\n";
    }
    
}