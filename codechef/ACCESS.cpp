/*  In the Name of ALLAH, the most gracious, the most merciful  */

// ACCESS - Access Control

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
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0' && cur == 0) {
            cout << "NO" << nl;
            return;
        }
        if (s[i] == '1') {
            cur = x;
        } else {
            cur--;
        }
    }
    cout << "YES" << nl;
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