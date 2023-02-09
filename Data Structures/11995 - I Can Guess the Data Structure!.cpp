#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
int main(){
    fastio
    int n;
    while(cin>>n){
        stack<int> st;
        queue<int> q;
        priority_queue<int> pq;
        int op,x,querys=0,ans[]={0,0,0};
        for(int i=0;i<n;i++){
            cin>>op>>x;
            if(op==1){
                st.push(x);
                q.push(x);
                pq.push(x);
            }else{
                querys++;
                if(!st.empty()){
                    ans[0]+=st.top()==x;
                    st.pop();
                }
                if(!q.empty()){
                    ans[1]+=q.front()==x;
                    q.pop();
                }
                if(!pq.empty()){
                    ans[2]+=pq.top()==x;
                    pq.pop();
                }
            }
        }
        int mx = *max_element(ans,ans+3);
        int cnt = count(ans,ans+3,mx);
        if(mx!=querys)cout<<"impossible";
        else if(cnt>1)cout<<"not sure";
        else if(ans[0]==mx)cout<<"stack";
        else if(ans[1]==mx)cout<<"queue";
        else cout<<"priority queue";
        cout<<"\n";
    }
}