#include <bits/stdc++.h>

using namespace std;
#define vi vector<int>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

bool isPrime(int n){
    for (size_t i = 2; i*i <= n; i++)
    {
        if(n%i==0) return false;
    }
    return true;
}

int n;
void buildRing(int prev,vi &sol,int solp,vi &used){
    if(solp>=sol.size()){
        if(isPrime(sol[0]+sol[sol.size()-1])){
            for (size_t i = 0; i < sol.size(); i++)
            {
                if(i>0)cout<<" ";
                cout<<sol[i];
            }
            cout<<"\n";
        }
        used[prev]=0;
        return;
    }

    for (int i = 2; i <=n; i++)
    {
        if(!used[i] && isPrime(prev+i)){
            sol[solp]=i;
            used[i]=1;
            buildRing(i,sol,solp+1,used);
        }
    }
    used[prev]=0;
}

vi used,sol;
int main(){
    fastio
    int t=1;
    while (cin>>n)
    {
        if(t>1) cout<<"\n";
        sol.assign(n,0);
        used.assign(n+1,0);
        sol[0]=1;
        used[1]=1;
        cout<<"Case "<<t++<<":\n";
        buildRing(1,sol,1,used);
    }
        
}