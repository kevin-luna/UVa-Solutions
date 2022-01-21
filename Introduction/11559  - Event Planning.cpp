#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N,B,H,W;

    while(cin>>N>>B>>H>>W){
        int price4Person,weekendPrice;
        int beds;
        vector<int> prices;
        for (size_t i = 1; i <= H; i++)
        {
            cin>>price4Person;
            weekendPrice=price4Person*N;
            for (size_t weekend = 1; weekend <=W; weekend++)
            {
                cin>>beds;
                if(beds>=N && weekendPrice<=B){
                    prices.push_back(weekendPrice);
                }
            }
            
        }
        if(prices.size()<=0){
            cout<<"stay home"<<"\n";
        }else{
            cout<<*min_element(prices.begin(),prices.end())<<"\n";
        }
    }
    


    return 0;
}
