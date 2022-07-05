#include <bits/stdc++.h>

using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

double p,q,r,s,t,u;
double evaluate(double x){
    return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}

int main(){
    fastio
    while(cin>>p>>q>>r>>s>>t>>u){
        double L=0.0,R=1.0,mid=0.0;
        while(R-L>=1e-9){
            mid=(L+R)/2.0;
            if(evaluate(mid)>=0) L=mid;
            else R=mid;
        }
        if(abs(evaluate(mid))<=1e-4) printf("%.4f\n",mid);
        else printf("No solution\n");
    }
}