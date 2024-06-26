/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Inverted Pyramid

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e5;

void fun(int cur, int n) {
    if (cur == n + 1) return;
    fun(cur + 1, n);
    for (int i = 0; i < n - cur; i++) {
        cout << " ";
    }
    for (int i = 0; i < 2 * cur - 1; i++) {
        cout << "*";
    }
    cout << nl;
}

void solve() {
    int n;
    cin >> n;
    fun(1, n);
    cout << nl;
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