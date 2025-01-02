/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Repeated Sequence

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
    ll s;
    cin >> n >> s;
    
    vector<int> A(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        sum += A[i];
    }
    
    vector<ll> pref(n + 1);
    set<ll> pset = {0};
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + A[i];
        pset.insert(pref[i]);
    }
    
    vector<ll> suff(n + 2);
    set<ll> sset = {0};
    for (int i = n; i > 0; i--) {
        suff[i] = suff[i + 1] + A[i];
        sset.insert(suff[i]);
    }
    
    for (int i = 0; i <= n; i++) {
        ll rem = s - pref[i];
        if (sset.find(rem % sum) != sset.end()) {
            cout << "Yes" << nl;
            return;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        ll rem = s - suff[i];
        if (pset.find(rem % sum) != pset.end()) {
            cout << "Yes" << nl;
            return;
        }
    }
    
    cout << "No" << nl;
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