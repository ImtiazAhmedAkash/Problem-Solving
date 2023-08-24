/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Strong Vertices

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define N 200005
#define deb(x) cerr << #x << " = " << x << nl
const ll mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b[i] = a[i] - x;
    }
    int mx = *max_element(b.begin(), b.end());
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (b[i] == mx) ans.push_back(i + 1);
    }
    cout << ans.size() << nl;
    for (auto &x : ans) cout << x << " ";
    cout << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}