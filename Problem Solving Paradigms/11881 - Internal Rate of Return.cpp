#include <iostream>
#include <iomanip>

using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int CF[11];

int t;
double NPV(double IRR) {
	double NPV = CF[0];
	double den = 1;
	for (size_t i = 1; i <= t; i++) {
		den *= (1 + IRR);
		NPV += CF[i] / den;
	}
	return NPV;
}

int main() {
    fastio
	while (cin >> t && t!=0) {
		for (size_t i = 0; i <= t; i++) {
			cin >> CF[i];
		}
		double L = -1.0, R = 1000.0,mid=0,sol=0;
		int solcnt = 0;
		while (abs(R-L)>1e-9)
		{
			mid = (L + R) / 2;
			double result = NPV(mid);
				if (result>0 && result <= 1e-3) {
					solcnt+= abs(sol-mid)>=1e-2 ? 1:0;
					if (solcnt == 1) {
						sol = mid;
					}
					else
					{
						cout << "Too many\n";
						break;
					}
				}
			
			if (result >= 0.0) {
				L = mid;
			}
			else R = mid;
		}
		if (solcnt == 0) cout << "No\n";
		else if (solcnt == 1) cout << setprecision(2) << fixed << sol <<"\n";
	}

}