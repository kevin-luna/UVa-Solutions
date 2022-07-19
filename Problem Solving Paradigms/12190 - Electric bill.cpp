#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int prices[][2]={{2,100},{3,9900},{5,990000},{7,1}};
ll calcCons(ll billing){
    ll cons=0;
    for (int i = 0; i < 4 && billing; i++)
    {
        if(i==3||billing<prices[i][0]*prices[i][1]){
            cons+=billing/prices[i][0];
            billing=0;
        }else{
            billing-=prices[i][0]*prices[i][1];
            cons+=prices[i][1];
        }
    }
    return cons;
}

ll calcBill(ll cons){
    ll pay=0;
    for (int i = 0; i < 4 && cons; i++)
    {
        if(cons-prices[i][1]<0 || i==3){
            pay+=prices[i][0]*cons;
            cons-=cons;
        }else{
            pay+=prices[i][0]*prices[i][1];
            cons-=prices[i][1];
        }
    }
    return pay;
}

ll A,B;

int main(){
    fastio
    while (cin>>A>>B && A+B!=0)
    {
        
        ll ttalCons=calcCons(A),L=0,R=(ttalCons/2)+1,mid=0,myBill=0,ngBill=0;
        while(L!=R){
            // cout<<L<<" "<<R<<"\n";
            mid = (L+R)/2;
            myBill = calcBill(mid),ngBill=calcBill(ttalCons-mid);
            ll dif = ngBill-myBill;
            // cout<<L<<" "<<mid<<" "<<R<<" "<<dif<<"\n";
            if(dif==B)break;
            if(dif<B)
                R=mid;
            else
                L=mid+1;
            
        }
        cout<<myBill<<"\n";
    }
    
}