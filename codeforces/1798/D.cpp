/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Shocking Arrangement

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
    ll maxi = -inf, mini = inf;
    vector<ll> pos, neg;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        maxi = max(maxi, x);
        mini = min(mini, x);
        if (x < 0) {
            neg.push_back(x);
        } else {
            pos.push_back(x);
        }
    }
    
    ll diff = maxi - mini;
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end(), greater());
    
    vector<int> ans;
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        if (!pos.empty() && max(abs(cur + pos.back()), pos.back()) < diff) {
            cur = max(abs(cur + pos.back()), pos.back());
            ans.push_back(pos.back());
            pos.pop_back();
        } else if (!neg.empty() && max(abs(cur + neg.back()), abs(neg.back())) < diff) {
            cur = max(abs(cur + neg.back()), neg.back());
            ans.push_back(neg.back());
            neg.pop_back();
        } else {
            cout << "No" << nl;
            return;
        }
    }
    
    cout << "Yes" << nl;
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i + 1 == n];
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