/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Karen and Coffee

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
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> cnt(N);
    
    while(n--) {
        int l, r;
        cin >> l >> r;
        cnt[l]++, cnt[r + 1]--;
    }
    partial_sum(cnt.begin(), cnt.end(), cnt.begin());
    for (int i = 1; i < N; i++) {
        cnt[i] = (cnt[i] >= k);
    }
    partial_sum(cnt.begin(), cnt.end(), cnt.begin());
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << cnt[r] - cnt[l - 1] << nl;
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