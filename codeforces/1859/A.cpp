/*  In the Name of ALLAH, the most gracious, the most merciful  */

// United We Stand

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl
const ll mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    if (a.front() == a.back()) {
        cout << -1 << nl;
    } else {
        int i = 0;
        vector<int> b, c;
        for (; i < n && a[i] != a.back(); i++) b.push_back(a[i]);
        for (; i < n; i++) c.push_back(a[i]);
        cout << b.size() << " " << c.size() << nl;
        for (auto x : b) cout << x << " ";
        cout << nl;
        for (auto x : c) cout << x << " ";
        cout << nl;
    }
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