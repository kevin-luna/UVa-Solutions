#include <iostream>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t=1;
    int n,e;
    while (cin>>n && n!=0)
    {
        int g=0,ng=0;
        for (int i = 1; i <= n; i++)
        {
            cin>>e;
            if(e>0){
                ++ng;
            }else{
                ++g;
            }
        }
        cout<<"Case "<<t++<<": "<<ng-g<<"\n";
    }
    
}