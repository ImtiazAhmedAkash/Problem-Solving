/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Joint Two Strings

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
    string t;
    cin >> t;
    vector<string> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    auto calculate_prefix = [&](string s) {
        int indx = 0;
        for (int i = 0; i < s.size() && indx < t.size(); i++) {
            if (s[i] == t[indx]) indx++;
        }
        return indx;
    };

    auto calculate_suffix = [&](string s) {
        int indx = t.size() - 1;
        for (int i = s.size() - 1; ~i && ~indx; i--) {
            if (s[i] == t[indx]) indx--;
        }
        return t.size() - indx - 1;
    };

    vector<int> P(n), S(n);
    for (int i = 0; i < n; i++) {
        P[i] = calculate_prefix(A[i]);
        S[i] = calculate_suffix(A[i]);
    }
    sort(S.begin(), S.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll cur = lower_bound(S.begin(), S.end(), (int)t.size() - P[i]) - S.begin();
        ans += n - cur;
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