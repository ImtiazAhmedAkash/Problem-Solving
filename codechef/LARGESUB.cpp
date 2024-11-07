/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// LARGESUB - Largest Subsequence

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

    auto check = [&](char first_char) -> int {
        int ans = 0;
        int i = s.find(first_char);
        if (i == -1) return 0;
        int tmp = 0;
        for (i; i < n; i++) {
            if (s[i] == first_char) {
                ans++;
                ans += tmp;
                tmp = 0;
            } else {
                tmp++;
            }
        }
        return ans;
    };

    int ans = max(check('a'), check('b'));
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