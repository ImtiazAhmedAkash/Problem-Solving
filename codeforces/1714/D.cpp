/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Color with Occurrences

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
    string s;
    cin >> s;
    int m = s.size();

    int n;
    cin >> n;
    vector<string> A(n);
    for (auto &x : A) cin >> x;

    vector<pair<int, int>> ans;
    int l = 0, r = 0;
    while (r < m) {
        int mx = r, start = -1, indx = -1;
        for (int i = l; i <= r; i++) {
            for (int j = 0; j < n; j++) {
                if (i + A[j].size() > m) continue;
                int sz = A[j].size();
                if (s.substr(i, sz) == A[j] && mx < i + sz) {
                    mx = i + sz;
                    start = i;
                    indx = j;
                }
            }
        }

        if (mx == r) {
            cout << -1 << nl;
            return;
        }

        ans.push_back({indx, start});
        l++;
        r = start + A[indx].size();
    }

    cout << ans.size() << nl;
    for (auto &[x, y] : ans) {
        cout << x + 1 << " " << y + 1 << nl;
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