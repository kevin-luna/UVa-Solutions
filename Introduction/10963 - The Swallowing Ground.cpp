#include <iostream>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;
    int north,south; 
    for (int i = 1; i <= t; i++)
    {   
        int min_south=100,max_north=-100,max_hs=0,max_hn=0,max_g=0,min_g=201;
        int rows,h;
        cin>>rows;
        for (int j = 0; j < rows; j++)
        {
            cin>>north>>south;
            h = (north>south) ? north-south+1 : south-north+1;

            if(h>max_g) max_g=h;
            if(h<min_g) min_g=h;

            if(south<min_south){
                min_south=south;
                max_hs= h;
            }

            if(north>max_north){
                max_north=north;
                max_hn= h;
            }
        }
        
        if(max_g<=max_hs && max_g<=max_hn && min_g==max_hs && min_g==max_hn) cout<<"yes\n";
        else cout<<"no\n";

        if(i<t) cout<<"\n";
        // cout<<"la altura maxima global es de "<<max_g<<"\n";
        // cout<<"la altura minima global es de "<<min_g<<"\n";
        // cout<<"la altura maxima posible hacia el norte es de "<<max_hn<<"\n";
        // cout<<"la altura maxima posible hacia el sur es de "<<max_hs<<"\n";
    }
}