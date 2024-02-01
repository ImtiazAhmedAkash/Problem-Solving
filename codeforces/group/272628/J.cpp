/*  In the Name of ALLAH, the most gracious, the most merciful  */

// The Da Vinci Code

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
    ll x;
    cin >> n >> x;
    vector<ll> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    vector<ll> pref(n + 1);
    partial_sum(A.begin(), A.end(), pref.begin());

    auto check = [&](int mid) -> bool {
        for (int i = mid; i <= n; i++) {
            if (x < pref[i] - pref[i - mid]) {
                return false;
            }
        }
        return true;
    };

    int L = 0, R = n;
    while (L < R) {
        int M = L + (R - L + 1) / 2;
        if (check(M)) {
            L = M;
        } else {
            R = M - 1;
        }
    }
    cout << (L == 0 ? -1 : L) << nl;
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