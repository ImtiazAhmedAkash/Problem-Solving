/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Okabe and Boxes

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
    stack<int> stk;
    int cur = 1;
    int ans = 0;
    for (int i = 0; i < 2 * n; i++) {
        string s;
        cin >> s;
        if (s == "add") {
            int x;
            cin >> x;
            stk.push(x);
            continue;
        }
        if (!stk.empty()) {
            if (stk.top() == cur) {
                stk.pop();
            } else {
                while (!stk.empty()) {
                    stk.pop();
                }
                ans++;
            }
        }
        cur++;
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