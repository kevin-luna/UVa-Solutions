#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int specimens[15];
int main(){
    fastio
    int c,s,t=1;
    while (cin>>c>>s)
    {
        cout<<"Set #"<<t++<<"\n";
        double avg=0.0,imbalance=0.0;
        int dummy=2*c-s;
        for (size_t i = 0; i < dummy; i++)
        {
            specimens[i]=0;
        }
        for (size_t i = dummy; i < 2*c; i++)
        {
            cin>>specimens[i];
            avg+=specimens[i];
        }
        avg/=c;
        sort(specimens,specimens+2*c);
        for (size_t i = 0; i < c; i++)
        {
            cout<<" "<<i<<":";
            if(specimens[i])cout<<" "<<specimens[i];
            if(specimens[2*c-i-1]) cout<<" "<<specimens[2*c-i-1];
            cout<<"\n";
            imbalance+=fabs(avg-(specimens[i]+specimens[2*c-i-1]));
        }
        cout<<"IMBALANCE = "<<fixed<<setprecision(5)<<imbalance<<"\n\n";
    }
    
}