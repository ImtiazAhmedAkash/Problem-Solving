/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Exactly Three Bits

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

vector<ll> A;
void precalculate() {
    for (int i = 0; i <= 60; i++) {
        for (int j = i + 1; j <= 60; j++) {
            for (int k = j + 1; k <= 60; k++) {
                ll cur = (1LL << i) + (1LL << j) + (1LL << k);
                A.push_back(cur);
            }
        }
    }
    sort(A.begin(), A.end());
}

void solve() {
    ll n;
    cin >> n;
    auto it = upper_bound(A.begin(), A.end(), n);
    cout << (it == A.begin() ? -1 : *prev(it)) << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    precalculate();

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}