#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
    fastio
    int L;
    string s;
    s.reserve(2000005);
    while (cin>>L)
    {
        if(L==0)break;
        cin>>s;
        int mind=2000005,lastR=-L,lastD=-L;
        for (int i = 0; i < L; i++)
        {
            if(s[i]=='Z'){mind=0;break;}
            else if(s[i]=='R'){
                mind=min(mind,i-lastD);
                lastR=i;
            }else if(s[i]=='D'){
                mind=min(mind,i-lastR);
                lastD=i;
            }
        }
        cout<<mind<<"\n";
    }
}