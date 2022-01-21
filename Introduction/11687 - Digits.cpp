#include <iostream>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string n;
    while (cin>>n && n!="END")
    {
        int i=1;
        if(n.length()==1 && n!="1") i=2;
        else if(n.length()>1){
            int digits=n.length(),prev=0;
            while (digits!=prev)
            {
                prev=digits;
                digits=to_string(digits).length();
                i++;
            }
        }
        cout<<i<<"\n";
    }
    
}