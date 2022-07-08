#include <bits/stdc++.h>

using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int books[100000];

int main(){
    fastio
    int N,M,T=1;
    while(cin>>N){
        for (size_t i = 0; i < N; i++)
        {
            cin>>books[i];
        }
        cin>>M;
        int min=1000000,b1=0,b2=0;
        sort(books,books+N);
        for (size_t j = 0; j < N; j++)
        {
            int dif=abs(M-2*books[j]);
            if(binary_search(books+j+1,books+N,M-books[j]) && dif<min){
                b1=books[j];
                b2=M-books[j];
                min=abs(b2-books[j]);
            }
        }
        cout<<"Peter should buy books whose prices are "<<b1<<" and "<<b2<<".\n\n";
    }
}