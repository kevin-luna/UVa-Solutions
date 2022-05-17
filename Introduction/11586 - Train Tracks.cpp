#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    cin.ignore();
    for (int i = 0; i < t; i++)
    {
        string tmp;
        getline(cin,tmp);
        int cnt=0;
        for (auto &c : tmp)
        {
            if(c=='M') ++cnt;
            else if(c=='F') --cnt;
        }
        cout<<(cnt==0 && tmp.size()>3 ? "LOOP\n":"NO LOOP\n");
    }   
}
