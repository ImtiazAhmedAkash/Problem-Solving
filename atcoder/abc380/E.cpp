/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// 1D Bucket Tool

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
    map<int, int> mp;
    mp[0] = 0;
    for (int i = 1; i <= n; i++) {
        mp[i] = i;
    }
    mp[n + 1] = 0;
    
    vector<int> cnt(n + 1, 1);
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, c;
            cin >> x >> c;
            
            auto it = prev(mp.upper_bound(x));
            int amount = (*next(it)).first - (*it).first;
            cnt[(*it).second] -= amount;
            (*it).second = c;
            cnt[c] += amount;
            
            if ((*next(it)).second == c) {
                mp.erase(next(it));
            }
            if ((*prev(it)).second == c) {
                mp.erase(it);
            }
        } 
        else {
            int c;
            cin >> c;
            cout << cnt[c] << nl;
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