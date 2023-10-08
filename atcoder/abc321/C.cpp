/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 321-like Searcher

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
    vector<ll> A;
    for (int val = 1; val < (1 << 10); val++) {
        ll cur = 0;
        for (int bit = 9; bit >= 0; bit--) {
            if (val & (1 << bit)) {
                cur *= 10;
                cur += bit;
            }
        }
        A.push_back(cur);
    }
    sort(A.begin(), A.end());
    int n;
    cin >> n;
    cout << A[n] << nl;
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