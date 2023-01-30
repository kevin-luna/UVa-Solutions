#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
int sol[50],pegs[50];
void precalc(){
    pegs[0]=0;
    int ball=1,last=0;
    while(last<50){
        bool put=0;
        for(int i=0;i<=last;i++){
            int root = sqrt(pegs[i]+ball);
            if(root*root==(pegs[i]+ball)){
                pegs[i]=ball++;
                put=1;
                break;
            }
        }
        if(!put){
            sol[last]=ball-1;
            pegs[++last]=ball++;
        }
    }
}
int main(){
    fastio
    precalc();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<sol[n-1]<<"\n";
    }
}