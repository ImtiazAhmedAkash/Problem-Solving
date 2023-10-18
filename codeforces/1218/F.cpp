/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Workout plan

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
    ll n, k;
    cin >> n >> k;
    vector<ll> A(n), C(n);
    for (auto &x : A) cin >> x;
    ll p;
    cin >> p;
    for (auto &x : C) cin >> x;
    priority_queue<ll, vector<ll>, greater<ll>> PQ;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        PQ.push(C[i]);
        while (A[i] > k) {
            if (PQ.empty()) {
                cout << -1 << nl;
                return;
            }
            k += p;
            ans += PQ.top();
            PQ.pop();
        }
    }
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