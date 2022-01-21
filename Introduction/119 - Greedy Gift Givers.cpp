#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n,t=1;
    while(cin>>n){
        vector<string> names;
        map<string,int> group;
        string name;
        for(int i=0;i<n;i++){
            cin>>name;
            names.push_back(name);
            group[name]=0;
        }
        int spent,ngiven;
        for(int j=0;j<n;j++){
            cin>>name>>spent>>ngiven;

            if(ngiven>0){
                group[name]-= (ngiven!=0) ? spent-(spent%ngiven) : spent;

                for(int k=0;k<ngiven;k++){
                    cin>>name;
                    group[name]+=spent/ngiven;
                }

            }

        }

        if(t++>1) cout<<"\n";
        for(int i=0;i<n;i++){
            cout<<names[i]<<" "<<group[names[i]]<<"\n";
        }
    }
}