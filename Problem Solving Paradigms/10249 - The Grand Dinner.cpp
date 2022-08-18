#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
    fastio
    int m,n;
    pii teams[75],tables[55];
    int ans[75][105];
    while (cin>>m>>n)
    {
        if(m==0 && n==0)break;
        int mx=0,people=0,maxcap=0;
        for (size_t i = 0; i < m; i++)
        {
            cin>>teams[i].first;
            teams[i].second=i+1;
            people+=teams[i].first;
            mx=max(teams[i].first,mx);
        }
        for(size_t i=0;i<n;i++){
            cin>>tables[i].first;
            tables[i].second=i+1;
            maxcap+=tables[i].first;
        }
        if(mx>n || people>maxcap){cout<<"0\n";continue;}
        sort(teams,teams+m,greater<pii>());
        // sort(tables,tables+n,greater<pii>());
        // for (size_t i=0;i<m;i++)cout<<teams[i].first<<" "<<teams[i].second<<"\n";cout<<"\n";
        // for(size_t i=0;i<n;i++)cout<<tables[i].first<<" "<<tables[i].second<<"\n";cout<<"\n";
        memset(ans,0,sizeof(ans));
        for (size_t i = 0; i < m; i++)//por cada equipo
        {
            sort(tables,tables+n,greater<pii>());
            //asignar mesas
            for (size_t j = 0; j < n && teams[i].first>0; j++)
            {
                if(tables[j].first>0){
                    --people;
                    --teams[i].first;
                    --tables[j].first;
                    ans[teams[i].second][tables[j].second]=1;
                }
            }
        }
        if(people!=0){
            cout<<"0\n";
        }else{
            cout<<"1\n";
            for (size_t i = 1; i <= m; i++)
            {
                bool space=false;
                for (size_t j = 1; j <=50; j++)
                {
                    if(ans[i][j]){
                        cout<<(space?" ":"")<<j;
                        space=true;
                    }
                }
                cout<<"\n";
            }
        }

    }
}