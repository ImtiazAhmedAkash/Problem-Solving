/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Lucky Numbers (easy)

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
    
    set<ll> st;
    auto dfs = [&](auto&& self, ll val, int four, int seven) -> void {
        if (four + seven > 10) return;
        if (four == seven) {
            st.insert(val);
        }
        self(self, val * 10 + 4, four + 1, seven);
        self(self, val * 10 + 7, four, seven + 1);
    };
    
    dfs(dfs, 0, 0, 0);
    
    auto it = st.lower_bound(n);
    cout << *it << nl;
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