/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Buggy Sorting

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
    int n;
    cin >> n;
    if (n < 3) cout << -1 << nl;
    else {
        cout << 2 << " " << 2 << " ";
        for (int i = 1; i <= n - 2; i++) cout << 1 << " ";
        cout << nl;
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