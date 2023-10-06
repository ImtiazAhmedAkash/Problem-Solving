/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Salyg1n and the MEX Game

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = (1LL << 62);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    int mx = n;
    for (int i = 0; i < n; i++) {
        if (a[i] != i) {
            mx = i;
            break;
        }
    }
    while (true) {
        cout << mx << endl;
        cin >> mx;
        if (mx == -1) break;
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