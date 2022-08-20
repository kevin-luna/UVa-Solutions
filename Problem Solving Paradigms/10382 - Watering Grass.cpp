#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef pair<int,int> pii;
struct sprinkler{
    int c;
    float radius,left,right;
    bool operator<(sprinkler const &a){
        return (left<a.left)?true:false;
    }
};
sprinkler s[10005];
bool covered(sprinkler i,double p){return (i.left<=p && i.right>=p);}
bool inside(pii i,sprinkler j){return i.first<=j.left && i.second>=j.right;}
int main(){
    fastio
    int n;
    double l,w,L,R;
    while (cin>>n>>l>>w)
    {
        double r=0.0,tmp=0.0;
        for (size_t i = 0; i < n; i++)
        {
            cin>>s[i].c>>s[i].radius;
            r=s[i].radius;
            tmp=r*r-(w*w/4.0);
            s[i].left= (tmp<0)? (-1):s[i].c-sqrt(tmp);
            s[i].right= (tmp<0)? (-1):s[i].c+sqrt(tmp);
        }
        sort(s,s+n);
        int ans=1;
        L=R=0.0;
        for (size_t i = 0; i < n; i++)
        {
            r=s[i].radius;
            if(s[i].right<L ||r*2<w || inside({L,R},s[i]))continue;
            if(R>=l)break;
            if(covered(s[i],L)){
                if(s[i].right>R){
                    R=s[i].right;
                }
            }else{
                if(covered(s[i],R)){
                    ++ans;
                    L=R;
                    if(s[i].right>R){
                        R=s[i].right;
                    }
                }else{
                    ans=-1;
                    break;
                }
            }
        }
        cout<<(R<l?-1:ans)<<"\n";
    }
}