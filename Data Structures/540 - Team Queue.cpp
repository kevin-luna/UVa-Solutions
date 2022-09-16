#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
    fastio
    int t,n,tn,teams[1000005],k=1;
    list<queue<int>> tq;
    while (cin>>t)
    {
        if(t==0)break;
        cout<<"Scenario #"<<k++<<"\n";
        tn=1;
        for (size_t i=0;i<t;i++)
        {
            cin>>n;
            int tmp;
            for (size_t j = 0; j < n;j++)
            {
                cin>>tmp;
                teams[tmp]=tn;
            }
            tn++;
        }
        string op;int e;
        while (cin>>op)
        {
            if(op=="STOP")break;
            if(op=="DEQUEUE"){
                cout<<tq.front().front()<<"\n";
                tq.front().pop();
                if(tq.front().empty())tq.pop_front();
            }else{
                cin>>e;
                bool found=false;
                for (queue<int> &i : tq)
                {
                    if(!i.empty() && teams[e]==teams[i.front()]){
                        i.push(e);
                        found=true;
                    }
                }
                if(!found){
                    tq.emplace_back();
                    tq.back().push(e);
                }
            }
        }
        cout<<"\n";
        tq.clear();
    }
}