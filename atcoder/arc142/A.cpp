/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Reverse and Minimize

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
    ll n, k;
    cin >> n >> k;
    string s = to_string(k);
    string t = s;
    while (t.back() == '0') {
        t.pop_back();
    }
    reverse(t.begin(), t.end());

    if (stoll(t) < stoll(s)) {
        cout << 0 << nl;
        return;
    }

    set<ll> st;
    while (stoll(s) <= n) {
        st.insert(stoll(s));
        s += '0';
    }
    while (stoll(t) <= n) {
        st.insert(stoll(t));
        t += '0';
    }
    cout << st.size() << nl;
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