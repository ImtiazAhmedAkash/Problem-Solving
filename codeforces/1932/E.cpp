/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Final Countdown

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
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + (s[i - 1] - '0');
    }

    vector<int> ans;
    int carry = 0;
    for (int i = n; i >= 1; i--) {
        int sum = carry + pref[i];
        ans.push_back(sum % 10);
        carry = sum / 10;
    }
    while (carry) {
        ans.push_back(carry % 10);
        carry /= 10;
    }

    while (ans.size() > 1 && ans.back() == 0) {
        ans.pop_back();
    }

    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }
    cout << nl;
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