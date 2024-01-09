/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Sorting Queries

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
    int q;
    cin >> q;
    queue<int> Q;
    multiset<int> ms;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            Q.push(x);
        } else if (op == 2) {
            int ans = 0;
            if (!ms.empty()) {
                ans = *ms.begin();
                ms.erase(ms.begin());
            } else {
                ans = Q.front();
                Q.pop();
            }
            cout << ans << nl;
        } else {
            while (!Q.empty()) {
                ms.insert(Q.front());
                Q.pop();
            }
        }
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