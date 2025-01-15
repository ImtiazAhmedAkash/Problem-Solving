/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Crafting

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 2e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    vector<int> B(n);
    for (auto &x : B) cin >> x;
    
    int cnt = 0;
    ll need = 0, have = inf;
    for (int i = 0; i < n; i++) {
        if (A[i] < B[i]) {
            cnt++;
            need += B[i] - A[i];
        } else {
            have = min(have, (ll) A[i] - B[i]);
        }
    }
    
    cout << ((cnt > 1 || need > have) ? "NO" : "YES") << nl;
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