/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Max - Min Query

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
    multiset<int> ms;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            ms.insert(x);
        } else if (op == 2) {
            int x, c;
            cin >> x >> c;
            while (c--) {
                if (ms.find(x) == ms.end()) break;
                ms.erase(ms.find(x));
            }
        } else {
            cout << (*ms.rbegin() - *ms.begin()) << nl;
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