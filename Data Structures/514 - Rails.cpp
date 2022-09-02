#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int n, tmp, p[1005], t = 1;
stack<int> s;
void reset(){while (!s.empty()) s.pop();}
int main(){
    fastio
    while (cin >> n){
        cout << (t++ > 1 ? "\n" : "");
        while (true){
            cin >> p[0];
            if (p[0] == 0)break;
            for (size_t i = 1; i < n; i++)cin >> p[i];
            int j = 0, a = 1;
            while (j < n){
                if (a <= n){
                    if (a == p[j]){a++;j++;}
                    else if (!s.empty() && s.top() == p[j]){s.pop();j++;}
                    else s.push(a++);
                }
                else if (!s.empty()){
                    if (s.top() == p[j]){s.pop();j++;}
                    else break;
                }
            }
            cout << (j == n ? "Yes" : "No") << "\n";
            reset();
        }
    }
}