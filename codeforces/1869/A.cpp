/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Make It Zero

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = (1 << 30);
const ll INF = (1LL << 62);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    if (n % 2 == 0) {
        cout << 2 << nl;
        cout << 1 << " " << n << nl;
        cout << 1 << " " << n << nl;
    } else {
        cout << 4 << nl;
        cout << 1 << " " << n << nl;
        cout << 1 << " " << n - 1 << nl;
        cout << n - 1 << " " << n << nl;
        cout << n - 1 << " " << n << nl;
    }
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