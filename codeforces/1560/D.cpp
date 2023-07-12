/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Make a Power of Two

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    string s;
    cin >> s;
    int ans = 20;
    for (int i = 0; i < 60; i++) {
        string res = to_string(1LL << i);
        int a = 0, b = 0, cnt = 0;
        while (a < s.size() && b < res.size()) {
            if (s[a] == res[b]) {
                a++, b++;
            } else {
                a++, cnt++;
            }
        }
        cnt += s.size() - a;
        cnt += res.size() - b;
        ans = min(ans, cnt);
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}