/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Measure

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
    string ans (n + 1, '-');
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= 9; j++) {
            if (n % j == 0 && i % (n / j) == 0) {
                ans[i] = j + '0';
                break;
            }
        }
    }
    cout << ans << nl;
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