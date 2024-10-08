/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Nim Game II

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
    int n;
    cin >> n;
    int x_or = 0;
    while (n--) {
        int x;
        cin >> x;
        x_or ^= (x % 4);
    }
    cout << (x_or ? "first" : "second") << nl;
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