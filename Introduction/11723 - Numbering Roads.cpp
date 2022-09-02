#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
    fastio
    int R,N,t=1;
    while (cin>>R>>N)
    {
        if(N==0 && R==0)break;
        cout<<"Case "<<t++<<": ";
        if(27*N<R)cout<<"impossible\n";
        else if(N>=R)cout<<0<<"\n";
        else{
            int n=N,prefix=0;
            while(n<R){++prefix;n+=N;}
            cout<<prefix<<"\n";
        }
    }
}