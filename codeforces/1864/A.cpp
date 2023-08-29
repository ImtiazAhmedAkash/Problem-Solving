/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Increasing and Decreasing

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int x, y, n;
    cin >> x >> y >> n;
    vector<int> a(n);
    a[0] = x;
    a[n - 1] = y;
    int k = 1;
    for (int i = n - 2; i >= 0; i--) {
        a[i] = a[i + 1] - k;
        k++;
    }
    if (a[0] < x) {
        cout << -1 << nl;
        return;
    }
    a[0] = x;
    for (auto x : a) cout << x << " ";
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