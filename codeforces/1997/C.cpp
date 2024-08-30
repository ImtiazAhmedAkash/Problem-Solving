/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Even Positions

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
    stack<int> stk;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '_') {
            if (stk.empty() || (stk.size() == 1 && s[i + 1] == ')')) {
                stk.push(i);
            } else {
                ans += i - stk.top();
                stk.pop();
            }
        } else if (s[i] == '(') {
            stk.push(i);
        } else {
            ans += i - stk.top();
            stk.pop();
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