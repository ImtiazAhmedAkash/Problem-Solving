/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Error Correction

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

    auto check = [&](string a, string b) {
        if (a.size() > b.size()) swap(a, b);
        int indx = 0;
        for (int i = 0; i < b.size(); i++) {
            if (a[indx] == b[i]) indx++;
            if (indx == a.size()) return true;
        }
        return false;
    };

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        string t;
        cin >> t;
        bool ok = false;
        if (s.size() == t.size()) {
            int diff = 0;
            for (int j = 0; j < s.size(); j++) {
                if (s[j] != t[j]) diff++;
            }
            if (diff <= 1) ok = true;
        } else if (abs((int)s.size() - (int)t.size()) == 1) {
            ok = check(s, t);
        }
        if (ok) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << nl;
    for (auto x : ans) cout << x << " ";
    cout << nl;
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