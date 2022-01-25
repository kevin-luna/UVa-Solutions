#include <iostream>
#include <utility>
using namespace std;

string song[] = {
    "Happy",
    "birthday",
    "to",
    "you",
    "Happy",
    "birthday",
    "to",
    "you",
    "Happy",
    "birthday",
    "to",
    "Rujia",
    "Happy",
    "birthday",
    "to",
    "you",
};

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;
    pair<string,int> people[105];
    for (int i = 0; i < n; i++)
    {
        cin>>people[i].first;
        people[i].second=0;
    }

    int sum=0,p=0,w=0;
    while (true)
    {
        cout<<people[p].first<<": "<<song[w]<<"\n";
        sum++;
        p++;
        w++;
        if(sum>=n && w>15) break;
        p = (p==n) ? 0 : p;
        w = (w>15) ? 0 : w;
    } 
    
}