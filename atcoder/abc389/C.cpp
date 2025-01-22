/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Snake Queue

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
    deque<pair<ll, ll>> dq;
    
    ll left = 0;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            if (dq.empty()) {
                dq.push_back({0, x});
            } else {
                auto [a, b] = dq.back();
                dq.push_back({a + b, x});
            }
        }
        else if (op == 2) {
            auto [a, b] = dq.front();
            dq.pop_front();
            left += b;
            if (dq.empty()) left = 0;
        } 
        else {
            int x;
            cin >> x;
            x--;
            cout << dq[x].first - left << nl;
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