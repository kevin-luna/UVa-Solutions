#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
    int t;
    cin>>t;
    int n;
    string field;
    field.reserve(105);
    for (size_t i = 1; i <= t; i++)
    {
        cin>>n>>field;
        int scarecrows=0;
        int j=0;
        while(j<n){
            if(field[j]=='.'){
                ++scarecrows;
                j+=3;
                continue;
            }
            j++;
        }
        cout<<"Case "<<i<<": "<<scarecrows<<"\n";
    }
}