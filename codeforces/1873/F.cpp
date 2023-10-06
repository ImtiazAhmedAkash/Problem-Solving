/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Money Trees

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
    vector<ll> A(n), H(n);
    int ans = 0;
    for (auto &x : A) {
        cin >> x;
        if (x <= k) ans = 1;
    }
    for (auto &x : H) 
        cin >> x;

    vector<pair<int, int>> indx;
    for (int i = 1; i < n; i++) {
        if (H[i - 1] % H[i] == 0) {
            int x = i - 1;
            while (i < n && H[i - 1] % H[i] == 0) i++;
            indx.push_back({x, i - 1});
        }
    }
    
    for (auto [a, b] : indx) {
        int cur = 0, cnt = 0, start = a;
        for (int i = a; i <= b;) {
            if (cur + A[i] <= k) {
                cur += A[i];
                cnt++, i++;
                ans = max(ans, cnt);
            } else if (start == i) {
                i++, start++;
            } else {
                cur -= A[start++];
                cnt--;
            }
        }
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