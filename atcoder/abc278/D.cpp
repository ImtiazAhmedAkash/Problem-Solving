/*  In the Name of ALLAH, the most gracious, the most merciful  */

// All Assign Point Add

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
    vector<ll> A(n + 1);
    for (int i = 1; i <= n; i++) cin >> A[i];
    set<int> S;
    for (int i = 1; i <= n; i++) {
        S.insert(i);
    }
    ll cur = 0;
    int q;
    cin >> q;
    while (q--) {
        int op, x, i;
        cin >> op;
        if (op == 1) {
            cin >> x;
            cur = x;
            S.clear();
        } else if (op == 2) {
            cin >> i >> x;
            if (S.find(i) == S.end()) {
                A[i] = cur;
                S.insert(i);
            }
            A[i] += x;
        } else {
            cin >> i;
            cout << (S.find(i) == S.end() ? cur : A[i]) << nl;
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