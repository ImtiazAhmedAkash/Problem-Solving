/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Bachgold Problem

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
    cout << n / 2 << nl;
    if (n & 1) {
        cout << 3 << " ";
        n -= 3;
    }
    for (int i = 1; i <= n / 2; i++) cout << 2 << " ";
    cout << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }
    
    return 0;
}