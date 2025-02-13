/*  In the Name of ALLAH, the most gracious, the most merciful  */

// B - Angry Monk

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
    int n, k;
    cin >> n >> k;
    vector<int> A(k + 1);
    for (int i = 1; i <= k; i++) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    ll ans = 0;
    for (int i = 1; i < k; i++) {
        ans += (2 * A[i] - 1);
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