#include <bits/stdc++.h>

using namespace std;

int main(){
    double p,l;
    int m,d;
    vector<double> dep;
    while (cin>>m>>p>>l>>d && m>0)
    {
        dep.assign(m,0);
        int month; float percent;
        for (int i = 0; i < d; i++)
        {
            cin>>month>>percent;
            for (int j = month; j < dep.size(); j++)
            {
                dep[j]=percent;
            }
        }
        
        double mp = l/m,cv=(l+p)*(1-dep[0]),cloan=l;
        int cdep =0;
        while (cloan>cv)
        {
            cloan-=mp;
            cv *= 1-dep[++cdep];
        }
        cout<<cdep<<" month";
        cout<<(cdep!=1 ? "s\n":"\n");
    }
    
}