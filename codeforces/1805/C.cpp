/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Place for a Selfie

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = (1 << 30);
const ll INF =(1LL << 62);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> line(n);
    for (auto &x : line) cin >> x;
    sort(line.begin(), line.end());
    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        int x = lower_bound(line.begin(), line.end(), b) - line.begin();
        if (x < n && (b - line[x]) * (b - line[x]) < 4 * a * c) {
            cout << "YES" << nl << line[x] << nl;
            continue;
        } 
        if (x > 0 && (b - line[x - 1]) * (b - line[x - 1]) < 4 * a * c) {
            cout << "YES" << nl << line[x - 1] << nl;
            continue;
        }
        cout << "NO" << nl;
    }
    cout << nl;
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