/*  In the Name of ALLAH, the most gracious, the most merciful  */

// In Love

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
    int n;
    cin >> n;
    multiset<pair<int, int>> S, R;
    while (n--) {
        char c;
        cin >> c;
        int l, r;
        cin >> l >> r;
        if (c == '+') {
            S.insert({l, r});
            R.insert({r, l});
        } else {
            S.erase(S.find({l, r}));
            R.erase(R.find({r, l}));
        }
        cout << (!S.empty() && (*S.rbegin()).first > (*R.begin()).first ? "YES" : "NO") << nl;
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