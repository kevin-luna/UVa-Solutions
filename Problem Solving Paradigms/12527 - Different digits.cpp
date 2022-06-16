#include <bits/stdc++.h>

using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
    fastio
    int n,m;
    int digits[10];
    while(cin>>n>>m){
        int norepeated=0;
        for (int i = n; i <= m; i++)
        {
            bool repeat=false;
            memset(digits,0,sizeof(digits));
            string s = to_string(i);
            for (int j = 0; j < s.size(); j++)
            {
                ++digits[s[j]-'0'];
                if(digits[s[j]-'0']>=2){
                    repeat=true;
                    continue;
                }
            }
            norepeated += !repeat ? 1:0;
        }
        cout<<norepeated<<"\n";
    }
}