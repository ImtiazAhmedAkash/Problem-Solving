/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Apple Division

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &x : A) {
        cin >> x;
    }
    
    ll ans = INF;
    auto fun = [&](auto&& self, int indx, ll x, ll y) -> void {
        if (indx == n) {
            ans = min(ans, abs(x - y));
            return;
        }
        self(self, indx + 1, x + A[indx], y);
        self(self, indx + 1, x, y + A[indx]);
    };
    
    fun(fun, 0, 0, 0);
    
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}