/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Perfect Standings

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
    int n = 5;
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    
    vector<pair<int, string>> B;
    for (int mask = 1; mask < (1 << n); mask++) {
        int cur = 0;
        string s;
        for (int bit = 0; bit < n; bit++) {
            if (mask & (1 << bit)) {
                cur += A[bit];
                s += (char)('A' + bit);
            }
        }
        B.push_back({cur, s});
    }
    
    sort(B.begin(), B.end(), [&](pair<int, string> x, pair<int, string> y) {
        if (x.first == y.first) return x.second < y.second;
        return x.first > y.first;
    });
    
    for (auto &[x, y] : B) {
        cout << y << nl;
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