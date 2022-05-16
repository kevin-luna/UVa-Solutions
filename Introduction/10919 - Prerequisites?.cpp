#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
    fastio
    int k,m;
    vi courses(10000,0);
    while (cin>>k>>m && k!=0)
    {
        courses.assign(10000,0);
        int c;
        for (int i = 0; i < k; i++)
        {
            cin>>c;
            courses[c]=1;
        }

        int catsize,min;
        bool met=true;
        for(int j=0;j<m;j++){
            cin>>catsize>>min;
            int selected=0,course;
            for (int j = 0; j < catsize; j++)
            {
                cin>>course;
                if(courses[course]==1) selected++;
            }

            if(selected<min) met=false;
        }
        
        if(met) cout<<"yes\n";
        else cout<<"no\n";
    }
}