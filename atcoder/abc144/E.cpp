/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Gluttony

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
    ll k;
    cin >> n >> k;
    vector<int> A(n), F(n);
    for (auto &x : A) cin >> x;
    for (auto &x : F) cin >> x;
    sort(A.begin(), A.end(), greater());
    sort(F.begin(), F.end());

    auto check = [&](ll mid) -> bool {
        ll need = 0;
        for (int i = 0; i < n; i++) {
            need += max(0LL, A[i] - mid / F[i]);
        }
        return need <= k;
    };

    ll L = 0, R = 1e13;
    while (L < R) {
        ll M = L + (R - L) / 2;
        if (check(M)) {
            R = M;
        } else {
            L = M + 1;
        }
    }
    cout << L << nl;
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