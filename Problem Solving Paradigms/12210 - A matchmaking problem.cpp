#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int d(int a,int b){return (a>b)?a-b:b-a;}
int main(){
    fastio
    int B,S,t=1;
    int b[10005],s[10005];
    while(cin>>B>>S){
        if(B==0 && S==0)break;
        for (size_t i = 0; i < B; i++)cin>>b[i];
        for (size_t i = 0; i < S; i++)cin>>s[i];
        if(B>S)for(size_t i=S;i<B;i++)s[i]=-1;
        sort(b,b+B,greater<int>());
        cout<<"Case "<<t++<<": ";
        int tb=B,ts=S;
        for (size_t i = 0; i < B && ts>0; i++)
        {
            int diff=70,k=0;
            for (size_t j = 0; j < S; j++)
            {
                if(d(b[i],s[j])<diff){
                    diff=d(b[i],s[j]);
                    k=j;
                }else break;
            }
            --tb;
            --ts;
            s[k]=-1;
            b[i]=-1;
        }
        cout<<tb;
        if(tb!=0){
            cout<<" ";
            for (size_t i = B-1; i>=0; i--)
            {
                if(b[i]!=-1){
                    cout<<b[i];
                    break;
                }
            }
        }
        cout<<"\n";
    }
}