/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Not Very Rude Substring

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
    ll c;
    cin >> n >> c;
    string s;
    cin >> s;
    int ans = 0;
    ll a = 0, b = 0, cur = 0;
    for (int l = 0, r = 0; r < n; r++) {
        if (s[r] == 'a') {
            a++;
        } else if (s[r] == 'b') {
            b++;
            cur += a;
        }
        while (l <= r && c < cur) {
            if (s[l] == 'a') {
                a--;
                cur -= b;
            } else if (s[l] == 'b') {
                b--;
            }
            l++;
        }
        ans = max(ans, r - l + 1);
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