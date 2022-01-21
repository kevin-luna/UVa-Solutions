#include <iostream>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n,l,prev=0; 
    cin>>n;

    cout<<"Lumberjacks:\n";
    for (int i = 0; i < n; i++)
    {
        int c=0,d=0;
        for (int j = 0; j < 10; j++)
        {
            cin>>l;
            if(j>0 && l<prev) ++d;
            else if(j>0 && l>prev) ++c;
            prev=l;
        }
        // cout<<c<<" "<<d<<"\n";
        if(c>=9 || d>=9) cout<<"Ordered\n";
        else cout<<"Unordered\n";
    }
}