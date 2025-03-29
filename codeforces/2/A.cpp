/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// A - Winner

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "Dbug.h"
#else
#define dbg(...)
#endif

using ll = long long;
constexpr char nl = '\n';

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<string> name(n + 5);
    map<string, int> mp;
    vector G(n + 5, vector<pair<int, int>>());
    vector<int> maxi(n + 5, -inf), time(n + 5, inf), cur(n + 5, 0);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int x;
        cin >> x;
        if (mp.find(s) == mp.end()) {
            mp[s] = mp.size();
        }
        
        int id = mp[s];
        name[id] = s;
        cur[id] += x;
        if (maxi[id] < cur[id]) {
            maxi[id] = cur[id];
            time[id] = i;
            G[id].push_back({cur[id], time[id]});
        }
    }
    
    int highestScore = *max_element(cur.begin(), cur.end());
    
    string ans;
    int timeOfScoring = inf;
    for (int i = 0; i < n; i++) {
        if (cur[i] != highestScore) continue;
        auto it = lower_bound(G[i].begin(), G[i].end(), make_pair(highestScore, 0));
        if (it == G[i].end()) continue;
        if ((*it).second < timeOfScoring) {
            timeOfScoring = (*it).second;
            ans = name[i];
        }
    }
    
    cout << ans << nl;
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