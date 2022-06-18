#include <bits/stdc++.h>

using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int marbles[10000];
int n,q;
size_t binarySearch(int q){
    int left=0,right=n-1,mid;
    while(left!=right){
        mid=(left+right)/2;
        if(q>marbles[mid]){
            left=mid+1;
        }else{
            right=mid;
        }
    }

    if(q==marbles[left])return left+1;
    else return -1;
}

int main(){
    fastio
    int t=1;
    while(cin>>n>>q && n+q!=0){
        cout<<"CASE# "<<t++<<":\n";
        for(size_t i=0;i<n;i++){
            cin>>marbles[i];
        }

        sort(marbles,marbles+n);
        int query,result;
        for(size_t j=0;j<q;j++){
            cin>>query;
            result=binarySearch(query);
            if(result!=-1){
                cout<<query<<" found at "<<result<<"\n";
            }else cout<<query<<" not found\n";
        }
    }
}