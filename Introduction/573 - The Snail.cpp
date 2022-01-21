#include <iostream>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    float u,h,d,f;
    while(cin>>h>>u>>d>>f){
        if(h!=0){
            float avance=0.0;int dias=0;
            f=u*f/100;
            while (true)
            {
                ++dias;
                avance += u;
                if(avance>h) break;
                avance-=d;
                if(u>0) u-=f;
                if(avance<0) break;
                
            }  

            if(avance<0){
                cout<<"failure on day "<<dias<<"\n";
            }else{
                cout<<"success on day "<<dias<<"\n";
            }
        }
    }

}