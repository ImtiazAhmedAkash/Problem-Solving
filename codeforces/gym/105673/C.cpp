/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Biggest Field (Hard Version)

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
    set<int> two, four;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
        if (mp[x] == 2) two.insert(x);
        else if (mp[x] == 4) four.insert(x);
    }
    
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            mp[x]++;
            if (mp[x] == 2) two.insert(x);
            else if (mp[x] == 4) four.insert(x);
        }
        else if (op == 2) {
            int x;
            cin >> x;
            if (!mp.count(x)) continue;
            if (mp[x] == 2) two.erase(x);
            if (mp[x] == 4) four.erase(x);
            mp[x]--;
            if (mp[x] == 0) mp.erase(x);
        }
        else {
            ll square = -1;
            if (!four.empty()) {
                int x = *four.rbegin();
                square = 1LL * x * x;
            }
            
            ll rectangle = -1;
            if (two.size() >= 2) {
                auto it = two.rbegin();
                int x = *it;
                int y = *next(it);
                rectangle = 1LL * x * y;
            }
            
            cout << square << " " << rectangle << nl;
        }
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