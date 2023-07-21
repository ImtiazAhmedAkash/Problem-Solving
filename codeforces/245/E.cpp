/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Mishap in Club

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
    int ans = 0, cnt = 0;
    for (auto i : s) {
        if (i == '+') {
            cnt++;
            ans = max(ans, cnt);
        } else {
            if (cnt) cnt--;
            else ans++;
        }
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}