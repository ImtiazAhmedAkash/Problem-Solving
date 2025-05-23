/*  In the Name of ALLAH, the most gracious, the most merciful  */

// C - Increasing Sequence with Fixed OR

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
    ll n;
    cin >> n;

    vector<ll> ans = {n};
    while (__lg(n) == __lg(ans.back())) {
        bool need_zero = true;
        bool ok = false;
        ll cur = ans.back();
        for (int bit = 0; bit <= __lg(n); bit++) {
            if (cur & (1LL << bit)) {
                if (need_zero) {
                    cur ^= (1LL << bit);
                    need_zero = false;
                }
            } else {
                if (n & (1LL << bit)) {
                    cur ^= (1LL << bit);
                    need_zero = true;
                }
            }

            if (cur && cur < ans.back() && ((cur | ans.back()) == n)) {
                ans.push_back(cur);
                ok = true;
                break;
            }
        }
        if (not ok) {
            break;
        }
    }
    reverse(ans.begin(), ans.end());
    
    cout << ans.size() << nl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << nl;
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