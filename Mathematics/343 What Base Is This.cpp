#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll asciiVal(char x){
    if(x>='A' && x<='Z')return (x-'A'+10);
    return (x-'0');
}

ll chBase(string &x,ll b){
    ll ans = 0, B=1;
    for(int i=(x.size()-1);i>=0;i--){
        ans+=asciiVal(x[i])*B;
        B*=b;
    }
    return ans;
}

int main() {
    string a,b;
    while(cin>>a>>b){
        bool solved=false;
        ll mxa=1,mxb=1;
        for(int i=0;i<a.size();i++)mxa=max(mxa, asciiVal(a[i]));
        for(int i=0;i<b.size();i++)mxb=max(mxb, asciiVal(b[i]));
        for(int i=mxa+1;i<=36 && !solved;i++){
            for(int j=mxb+1;j<=36 && !solved;j++){
                if(chBase(a,i)==chBase(b,j)){
                    cout<<a<<" (base "<<i<<") = "<<b<<" (base "<<j<<")"<<"\n";
                    solved=true;
                }
            }
        }
        if(!solved)cout<<a<<" is not equal to "<<b<<" in any base 2..36\n";
    }
    return 0;
}
