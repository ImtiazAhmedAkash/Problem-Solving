/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Same Count One

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
    int n, m;
    cin >> n >> m;
    vector A(n, vector<int>(m));
    vector<int> cnt(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
            sum += A[i][j];
            cnt[i] += A[i][j];
        }
    }

    if (sum % n) {
        cout << -1 << nl;
        return;
    }

    int need = sum / n;

    vector zeros(m, vector<int>());
    auto ones = zeros;

    for (int i = 0; i < n; i++) {
        if (cnt[i] > need) {
            for (int j = 0; j < m; j++) {
                if (A[i][j] == 1) {
                    ones[j].push_back(i);
                }
            }
        } else if (cnt[i] < need) {
            for (int j = 0; j < m; j++) {
                if (A[i][j] == 0) {
                    zeros[j].push_back(i);
                }
            }
        }
    }

    vector<array<int, 3>> ans;
    for (int i = 0; i < m; i++) {
        while (!ones[i].empty() && !zeros[i].empty()) {
            int x = ones[i].back();
            if (cnt[x] == need) {
                ones[i].pop_back();
                continue;
            }
            int y = zeros[i].back();
            if (cnt[y] == need) {
                zeros[i].pop_back();
                continue;
            }
            ans.push_back({x, y, i});
            ones[i].pop_back();
            zeros[i].pop_back();
            cnt[x]--, cnt[y]++;
        }
    }

    cout << ans.size() << nl;
    for (auto [x, y, z] : ans) {
        cout << x + 1 << " " << y + 1 << " " << z + 1 << nl;
    }
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