/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Kachina's Favorite Binary String

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

int ask(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n;
    cin >> n;
    string ans(n + 1, '1');

    if (ask(1, n) == 0) {
        cout << "! IMPOSSIBLE" << endl;
        return;
    }

    int last = -1;
    for (int i = 2; i <= n; i++) {
        int cur = ask(1, i);
        if (last == -1) {
            if (cur) {
                last = cur;
                int j = i - 1;
                while (cur--) {
                    ans[j--] = '0';
                }
            }
        } else {
            if (cur == last) {
                ans[i] = '0';
            }
            last = cur;
        }
    }

    ans.erase(ans.begin());
    cout << "! " << ans << endl;
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