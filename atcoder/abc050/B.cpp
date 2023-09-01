/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Contest with Drinks Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    int total = accumulate(p.begin(), p.end(), 0);
    int m;
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << total - p[a] + b << nl;
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