/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Ternary String

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

/*
 * Iterate the string and update the last positions of '1', '2' and '3'.
 * From the time, when all three elements are found,
 * calculate the minimum length between the three characters.
 * 
 * Formula: (maximum of their position - minimum of their position).
 * 1 is added here, because 1 based position is used.
 * The minimum length is the answer.
 */

void solve() {
    string s;
    cin >> s;
    vector<int> pos(4);
    int ans = INF;
    for (int i = 0; i < s.size(); i++) {
        pos[s[i] - '0'] = i + 1;
        if (pos[1] && pos[2] && pos[3]) {
            int tmp = max({pos[1], pos[2], pos[3]}) - min({pos[1], pos[2], pos[3]}) + 1;
            ans = min(ans, tmp);
        }
    }
    if (ans == INF) ans = 0;
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