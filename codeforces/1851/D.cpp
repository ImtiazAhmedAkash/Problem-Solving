/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Prefix Permutation Sums

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    ll n;
    cin >> n;
    set<ll> st;
    vector<ll> pref(n), extra;
    pref.front() = 0;
    for (int i = 1; i < n; i++) cin >> pref[i];
    for (int i = 1; i <= n; i++) st.insert(i);
    for (int i = 1; i < n; i++) {
        ll diff = pref[i] - pref[i - 1];
        if (st.find(diff) != st.end()) st.erase(diff);
        else extra.push_back(diff);
    }
    string ans;
    if (st.size() == 1) {
        if (extra.empty()) ans = "YES";
        else ans = "NO";
    } else if (st.size() == 2) {
        ll x = *(st.begin()) + *(st.rbegin());
        if (x == extra.front()) ans = "YES";
        else ans = "NO";
        
    } else ans = "NO";
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}