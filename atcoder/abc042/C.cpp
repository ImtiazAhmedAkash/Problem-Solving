/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Iroha's Obsession

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = (1 << 30);
const ll INF = (1LL << 62);
const int mod = 998244353;
const int N = 1e7 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    set<char> st;
    while (m--) {
        char x;
        cin >> x;
        st.insert(x);
    }
    while (true) {
        string s = to_string(n);
        bool ok = true;
        for (auto x : s) {
            if (st.find(x) != st.end()) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << s << nl;
            return;
        }
        n++;
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