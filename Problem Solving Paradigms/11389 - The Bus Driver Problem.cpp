#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int morning[105],afternoon[105];
int main(){
    int n,d,r;
    while(cin>>n>>d>>r && n+d+r!=0){
        for (size_t i = 0; i < n; i++)
        {
            cin>>morning[i];
        }
        for(size_t i=0;i<n;i++){
            cin>>afternoon[i];
        }
        sort(morning,morning+n);
        sort(afternoon,afternoon+n,greater<int>());
        int ac=0;
        for (size_t i = 0; i < n; i++)
        {
            int sum=afternoon[i]+morning[i];
            if(sum>d){
                int dif = sum-d;
                ac+=dif*r;
            }
        }
        cout<<ac<<"\n";
    }
}