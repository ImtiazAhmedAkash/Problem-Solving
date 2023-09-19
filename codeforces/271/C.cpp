/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Secret

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
    int n, k;
    cin >> n >> k;
    if (n / k < 3) {
        cout << -1 << nl;
        return;
    }
    int x = 1;
    for (int i = 1; i <= k; i++, x++) {
        cout << x << " " << x << " ";
    }
    n -= 2 * k;
    x = 1;
    while (n--) {
        cout << x << " ";
        x = (x % k) + 1;
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