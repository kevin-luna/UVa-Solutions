#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
struct interval{
    double l,r;
    bool operator<(interval const &a){return l<a.l;}
};
int n,d,t=1;
interval getinterval(interval &a){
    return{a.l-sqrt(d*d-a.r*a.r),a.l+sqrt(d*d-a.r*a.r)};
}
interval islands[1005];
int main(){
    fastio
    while (cin>>n>>d)
    {   
        if(n==0 && d==0)break;
        bool solve=true;
        for (size_t i = 0; i < n; i++)
        {
            cin>>islands[i].l>>islands[i].r;
            if(islands[i].r>d)solve=false;
            islands[i]=getinterval(islands[i]);
        }
        cout<<"Case "<<t++<<": ";
        if(!solve){cout<<"-1\n";continue;}
        sort(islands,islands+n);
        int radars=1;
        double curr=islands[0].r;
        for (size_t i = 1; i < n; i++)
        {
            if(islands[i].l>curr){;
                ++radars;
                curr=islands[i].r;
            }
            else if(islands[i].l<curr && islands[i].r<curr)curr=islands[i].r;
        }
        cout<<radars<<"\n";
    }
}