#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n,p;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        vector<pair<int,int>> min_neigbours;
        cin>>p;
        cin.ignore(1);
        min_neigbours.push_back(make_pair(0,p-1));
        string neighbours;
        for (int j = 1; j <= p; j++)
        {
            
            getline(cin,neighbours);
            int tn=count(neighbours.begin(),neighbours.end(),' ')+1;

            if(j==1 || tn<min_neigbours[0].second){//si hay un nuevo minimo o es el primer lugar
                min_neigbours = vector<pair<int,int>>(0);
                min_neigbours.push_back(make_pair(j,tn));
            }else if(tn==min_neigbours[0].second){
                min_neigbours.push_back(make_pair(j,tn));
            }
            
        }

        for (int k = 0; k < min_neigbours.size(); k++)
        {
            cout<<min_neigbours[k].first;
            if(k<min_neigbours.size()-1) cout<<" ";
        }
        cout<<"\n";
    }
    

}