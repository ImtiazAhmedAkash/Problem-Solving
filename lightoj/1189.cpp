/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 1189 - Sum of Factorials

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

vector<ll> F(20);

void calculate() {
    F[0] = 1;
    for (int i = 1; i < 20; i++) {
        F[i] = i * F[i - 1];
    }
}

void solve() {
    ll n;
    cin >> n;
    stack<int> stk;
    for (int i = 19; ~i && n; i--) {
        if (F[i] <= n) {
            stk.push(i);
            n -= F[i];
        }
    }
    
    if (n != 0) {
        cout << "impossible" << nl;
        return;
    }
    
    while(!stk.empty()) {
        cout << stk.top() << "!";
        stk.pop();
        cout << (stk.empty() ? '\n' : '+');
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    calculate();
    
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case " << t << ": ";
        solve();
    }
    
    return 0;
}