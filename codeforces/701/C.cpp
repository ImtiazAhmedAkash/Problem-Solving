/*  In the Name of ALLAH, the most gracious, the most merciful  */

// They Are Everywhere

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
    string s;
    cin >> s;
    set<char> st;
    for (auto x : s) {
        st.insert(x);
    }
    int total = st.size();
    map<char, int> M;
    int ans = inf, cur = 0;
    for (int l = 0, r = 0; r < n; r++) {
        M[s[r]]++;
        if (M[s[r]] == 1) cur++;
        while (l <= r && M[s[l]] > 1) {
            M[s[l]]--;
            l++;
        }
        if (cur == total) {
            ans = min(ans, r - l + 1);
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