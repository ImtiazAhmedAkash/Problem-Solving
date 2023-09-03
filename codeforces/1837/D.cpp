/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Bracket Coloring

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (count(s.begin(), s.end(), '(') != count(s.begin(), s.end(), ')')) {
        cout << -1 << nl;
        return;
    }
    vector<int> a(n, 0);
    stack<pair<char, int>> stk;
    int val = 1;
    bool ok = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') stk.push({'(', i});
        else if (s[i] == ')' && !stk.empty()) {
            a[stk.top().second] = 1;
            stk.pop();
            a[i] = val;
            ok = true;
        }
    }
    val += ok;
    for (auto &x : a) {
        if (x == 0) {
            x = val;
        }
    }
    while (!stk.empty()) {
        stk.pop();
    }
    val = 1;
    ok = false;
    reverse(s.begin(), s.end());
    vector<int> b(n, 0);
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') stk.push({'(', i});
        else if (s[i] == ')' && !stk.empty()) {
            b[stk.top().second] = 1;
            stk.pop();
            b[i] = val;
            ok = true;
        }
    }
    val += ok;
    for (auto &x : b) {
        if (x == 0) {
            x = val;
        }
    }
    int amx = *max_element(a.begin(), a.end());
    int bmx = *max_element(b.begin(), b.end());
    if (bmx < amx) {
        amx = bmx;
        a = b;
    }
    cout << amx << nl;
    for (auto x : a) cout << x << " ";
    cout << nl;
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