#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll x, y;

int main() {
	fastio
	while (cin>>x>>y) {
		int L = 0, R = INT_MAX, mid = 0,sol=0;
		while (L < R) {
			mid = L + (R - L) / 2;
			if (mid*(y-x) >= y)
                R=mid;
			else L = mid+1;
		}
		cout <<L << "\n";
	}
}