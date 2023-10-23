/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Decreasing String

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
    string s;
    cin >> s;
    ll pos;
    cin >> pos;
    int n = s.size();
    int str_id = 0, len = n;
    while (pos - len > 0) {
        pos -= len;
        len--;
        str_id++;
    }
    int cur_id = 0;
    stack<char> stk;
    stk.push(s[0]);
    for (int i = 1; i < n; i++) {
        while (!stk.empty() && stk.top() > s[i] && str_id != cur_id) {
            stk.pop();
            cur_id++;
        }
        stk.push(s[i]);
    }
    while (str_id != cur_id && !stk.empty()) {
        stk.pop();
        cur_id++;
    }
    s = "";
    while (!stk.empty()) {
        s += stk.top();
        stk.pop();
    }
    reverse(s.begin(), s.end());
    cout << s[pos - 1];
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