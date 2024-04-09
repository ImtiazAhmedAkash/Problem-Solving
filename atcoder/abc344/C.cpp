/*  In the Name of ALLAH, the most gracious, the most merciful  */

// A+B+C

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
    for (auto& x : A) cin >> x;

    int m;
    cin >> m;
    vector<int> B(m);
    for (auto& x : B) cin >> x;

    int l;
    cin >> l;
    vector<int> C(l);
    for (auto& x : C) cin >> x;

    map<int, bool> M;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < l; k++) {
                M[A[i] + B[j] + C[k]] = true;
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << (M.find(x) != M.end() ? "Yes" : "No") << nl;
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