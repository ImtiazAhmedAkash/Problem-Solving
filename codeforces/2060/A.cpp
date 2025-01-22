/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Fibonacciness

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
    vector<int> A(5);
    cin >> A[0] >> A[1] >> A[3] >> A[4];
    
    int ans = 0;
    for (int x = -200; x <= 200; x++) {
        A[2] = x;
        int cur = 0;
        for (int i = 2; i < 5; i++) {
            if (A[i - 2] + A[i - 1] == A[i]) {
                cur++;
            }
        }
        ans = max(ans, cur);
    }
    
    cout << ans << nl;
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