/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Sets and Union

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 55;

void solve() {
    int n;
    cin >> n;
    vector<int> Set[N], A[n], cnt(N, 0);
    int total = 0;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        while (m--) {
            int x;
            cin >> x;
            A[i].push_back(x);
            Set[x].push_back(i);
            cnt[x]++;
            if (cnt[x] == 1) total++;
        }
    }
    int ans = 0;
    for (int i = 1; i < N; i++) {
        if (Set[i].empty()) continue;
        int cur = 0;
        auto tmp = cnt;
        for (auto x : Set[i]) {
            for (auto y : A[x]) {
                tmp[y]--;
            }
        }
        for (int j = 1; j < N; j++) {
            if (tmp[j]) cur++;
        }
        if (cur != total) ans = max(ans, cur);
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