/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// The Butcher

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
    vector<pair<ll, ll>> A(n);
    ll area = 0;
    ll maxH = 0, maxW = 0;
    for (auto &[x, y] : A) {
        cin >> x >> y;
        area += x * y;
        maxH = max(maxH, x);
        maxW = max(maxW, y);
    }
    
    auto check = [&](ll curH, ll curW) -> bool {
        vector<int> used(n, false);
        priority_queue<pair<ll, ll>> pqH, pqW;
        for (int i = 0; i < n; i++) {
            pqH.push({A[i].first, i});
            pqW.push({A[i].second, i});
        }
        
        while (!pqH.empty() || !pqW.empty()) {
            while (!pqH.empty() && used[pqH.top().second]) {
                pqH.pop();
            }
            while (!pqW.empty() && used[pqW.top().second]) {
                pqW.pop();
            }
            
            if (!pqH.empty() && pqH.top().first == curH) {
                int indx = pqH.top().second;
                curW -= A[indx].second;
                used[indx] = true;
                pqH.pop();
            } else if (!pqW.empty() && pqW.top().first == curW) {
                int indx = pqW.top().second;
                curH -= A[indx].first;
                used[indx] = true;
                pqW.pop();
            } else {
                break;
            }
        }
        
        return pqH.empty() && pqW.empty();
    };
    
    set<pair<ll, ll>> ans;
    if (area % maxH == 0 && check(maxH, area / maxH)) {
        ans.insert({maxH, area / maxH});
    }
    if (area % maxW == 0 && check(area / maxW, maxW)) {
        ans.insert({area / maxW, maxW});
    }
    
    cout << ans.size() << nl;
    for (auto &[x, y] : ans) {
        cout << x << " " << y << nl;
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