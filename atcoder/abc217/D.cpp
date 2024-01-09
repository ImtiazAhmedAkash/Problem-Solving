/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Cutting Woods

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
    int n, q;
    cin >> n >> q;
    set<int> st = {0, n};
    while (q--) {
        int c, x;
        cin >> c >> x;
        if (c == 1) {
            st.insert(x);
        } else {
            auto it = st.lower_bound(x);
            cout << (*it - *prev(it)) << nl;
        }
    }
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