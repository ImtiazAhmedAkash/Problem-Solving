/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Unforgivable Curse (Hard Version)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    string ans = "YES";
    vector<int> a(26), b(26);
    for (auto x : s) a[x - 'a']++;
    for (auto x : t) b[x - 'a']++;
    if (a != b) ans = "NO";
    else {
        for (int i = 0; i < n; i++) {
            if (i - k < 0 && i + k >= n) {
                if (s[i] != t[i]) {
                    ans = "NO";
                }
            }
        }
    }
    cout << ans << nl;
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