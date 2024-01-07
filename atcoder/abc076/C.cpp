/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Dubious Document 2

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
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<string> A;
    for (int i = 0; i <= n - m; i++) {
        bool ok = true;
        for (int j = 0; j < m; j++) {
            if (s[i + j] != '?' && s[i + j] != t[j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            string x = "";
            for (int j = 0; j < i; j++) {
                x += (s[j] == '?' ? 'a' : s[j]);
            }
            for (int j = 0; j < m; j++) {
                x += t[j];
            }
            for (int j = i + m; j < n; j++) {
                x += (s[j] == '?' ? 'a' : s[j]);
            }
            A.push_back(x);
        }
    }
    sort(A.begin(), A.end());
    cout << (A.empty() ? "UNRESTORABLE" : A.front()) << nl;
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