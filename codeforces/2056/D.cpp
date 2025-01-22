/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Unique Median

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
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    auto bad_count = [&](int mid) -> ll {
        vector<int> pref(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (A[i] <= mid) pref[i] = 1;
            pref[i] += pref[i - 1];
        }
        
        map<int, int> mp;
        ll bad = 0;
        vector<int> wait = {0};
        for (int i = 1; i <= n; i++) {
            if (A[i] == mid) {
                for (auto &x : wait) {
                    mp[x]++;
                }
                wait.clear();
            }
            int val = 2 * pref[i] - i;
            if (mp.count(val)) {
                bad += mp[val];
            }
            wait.push_back(val);
        }
        
        return bad;
    };
    
    ll ans = 1LL * n * (n + 1) / 2;
    for (int i = 1; i <= 10; i++) {
        ans -= bad_count(i);
    }
    
    cout << ans << nl;
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