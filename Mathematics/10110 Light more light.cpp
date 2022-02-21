#include <iostream>
#include <cmath>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    unsigned int n;
    while (cin>>n && n!=0)
    {
        unsigned int tmp = sqrt(n);
        tmp*=tmp;
        cout<<(tmp==n ? "yes" : "no")<<"\n";
    }
    
}