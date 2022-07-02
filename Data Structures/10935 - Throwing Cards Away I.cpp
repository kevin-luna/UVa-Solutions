#include <bits/stdc++.h>

using namespace std;

int main(){
    list<int> deck;
    int n;
    
    while(cin>>n && n!=0){
        for(int i=1;i<=n;i++){
            deck.emplace_back(i);
        }
        cout<<"Discarded cards:";
        while (deck.size()>=2)
        {
            cout<<" "<<deck.front();
            deck.pop_front();
            int tmp=deck.front();
            deck.emplace_back(tmp);
            deck.pop_front();
            if(deck.size()>=2)cout<<",";
        }
        cout<<"\nRemaining card: "<<deck.front()<<"\n";
        deck.clear();
    }
}