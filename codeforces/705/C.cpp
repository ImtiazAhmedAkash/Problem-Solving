/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Thor

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
    int n, q;
    cin >> n >> q;
    vector<queue<int>> which(n + 1);
    vector<int> by(q + 1);
    int cur = 1, nf = 0;
    int ans = 0;

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            nf++, ans++;
            which[x].push(nf);
            by[nf] = x;
        } else if (op == 2) {
            int x;
            cin >> x;
            while (!which[x].empty()) {
                int y = which[x].front();
                which[x].pop();
                by[y] = -1;
                ans--;
            }
        } else {
            int t;
            cin >> t;
            while (cur <= t) {
                if (by[cur] != -1) {
                    int y = by[cur];
                    by[cur] = -1;
                    which[y].pop();
                    ans--;
                }
                cur++;
            }
        }
        cout << ans << nl;
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