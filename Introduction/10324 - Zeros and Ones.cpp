#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    string stream,temp;
    int ncase=1,n;
    int i,j;
    bool diff;
    while (cin>>stream)
    {
        cout<<"Case "<<ncase<<":"<<endl;
        cin>>n;
        for (size_t q = 1; q <= n; q++)
        {
            diff=false;
            cin>>i;
            cin>>j;
            temp = stream.substr(min(i,j),abs(i-j)+1);
            for (size_t pos = 0; pos < temp.length(); pos++)
            {
                if(temp[pos]!=temp[0]){
                    diff=true;
                    break;
                }
            }

            if(diff){
                cout<<"No"<<endl;
            }else{
                cout<<"Yes"<<endl;
            }
            
        }
        ncase++;
    }
    
    return 0;
}
