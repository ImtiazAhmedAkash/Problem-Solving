/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Doremy's Connecting Plan

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
    ll n, c;
    cin >> n >> c;
    vector<ll> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    int visited = 1, not_yet = 0;
    ll sum = A[1], cur = 0;
    for (int i = 2; i <= n; i++) {
        not_yet++;
        cur += A[i];
        if (sum + A[i] >= i * c) {
            sum += cur;
            visited += not_yet;
            cur = 0, not_yet = 0;
        }
    }
    cout << (visited == n ? "Yes" : "No") << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}