/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Bit Flipping

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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int change = 0;
    vector<int> ans(n);
    for (int i = 0; i < n - 1; i++) {
        if (change) {
            s[i] = (1 - (s[i] - '0')) + '0';
        }
        if ((m != 0 && m % 2 == 0 && s[i] == '0') || ((m & 1) && s[i] == '1')) {
            ans[i]++;
            m--;
            change = 1 - change;
        }
        if ((m & 1) || (m != 0 && m % 2 == 0 && s[i] == '0')) {
            s[i] = '1';
        }
    }

    if (change) {
        s.back() = (1 - (s.back() - '0')) + '0';
    }
    ans.back() += m;

    cout << s << nl;
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