#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);
int main(){
    fastio
    int n;
    int e1[500005],e2[500005];
    while (cin>>n)
    {
        if(n==0)break;
        bool solve=true;
        for (size_t i = 0; i < n; i++)
        {
            cin>>e1[i]>>e2[i];
        }
        sort(e1,e1+n);
        sort(e2,e2+n);
        for (size_t i = 0; i < n; i++)
        {
            if(e1[i]!=e2[i]){
                solve=false;
                break;
            }
        }
        cout<<(solve?"YES":"NO")<<"\n";
    }
}