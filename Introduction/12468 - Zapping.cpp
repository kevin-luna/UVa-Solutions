#include <iostream>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a,b;
    while (cin>>a>>b && a!=-1 && b!=-1)
    {
        int d1 = (a>b) ? a-b : b-a;
        int d2 = (a>b) ? (99-a+1)+b : (99-b+1)+a;//el +1 es porque no estaba contando el cambio del 0 al 99 cuando se cuenta hacia atrás
        int min = (d1<d2) ? d1 : d2;
        cout<<min<<"\n";
    }
    
    
}