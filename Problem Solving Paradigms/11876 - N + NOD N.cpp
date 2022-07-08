#include <bits/stdc++.h>

using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int cntDiv(int n)
{
    int cnt = 0;
    for (int i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            if (n / i == i)
                cnt++;
            else
                cnt = cnt + 2;
        }
    }
    return cnt;
}

int sq[64725];
int sq_size=0;

void genSqc(){
    int i=1;
    while (true)
    {
        sq[i]=sq[i-1]+cntDiv(sq[i-1]);
        if(sq[i]>=1000000)break;
        ++i;
    }
    sq_size=i;
}

int lb(int x){//returns sq[i]>=x
    int L=0,R=sq_size,mid=0;
    while (L!=R)
    {
        mid=(L+R)/2;
        if(sq[mid]>=x) R=mid;
        else L=mid+1;
    }
    return (L<sq_size && sq[L]<x)? mid:L;
}

int ub(int x){//returns sq[i]>x
    int L=0,R=sq_size,mid=0;
    while (L!=R)
    {
        mid=(L+R)/2;
        if(sq[mid]<=x) L=mid+1;
        else R=mid;
    }
    return (L<sq_size && sq[L]<=x)? mid:L;
}

int main(){
    fastio
    int t,A,B;
    sq[0]=1;
    genSqc();
    cin>>t;
    for (int i = 1; i <=t; i++)
    {
        cin>>A>>B;
        int pa=lb(A),pb=ub(B);
        cout<<"Case "<<i<<": "<<pb-pa<<"\n";
    }
}