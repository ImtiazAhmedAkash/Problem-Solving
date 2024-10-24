/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Nice Garland

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

    string t = "BGR";
    string ans = s;
    int move = inf;

    do {
        string cur;
        int i = 0;
        while (cur.size() != n) {
            cur += t[i];
            i++;
            i %= 3;
        }

        int cur_move = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != cur[i]) {
                cur_move++;
            }
        }

        if (cur_move < move) {
            move = cur_move;
            ans = cur;
        }

    } while (next_permutation(t.begin(), t.end()));

    cout << move << nl << ans << nl;
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