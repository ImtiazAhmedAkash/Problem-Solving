/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Special Trains

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
    vector<int> C(n + 1), S(n + 1), F(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> C[i] >> S[i] >> F[i];
    }
    for (int i = 1; i <= n; i++) {
        int cur = S[i] + C[i];
        for (int j = i + 1; j < n; j++) {
            cur = F[j] * ((max(cur, S[j]) + F[j] - 1) / F[j]);
            cur += C[j];
        }
        cout << cur << nl;
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