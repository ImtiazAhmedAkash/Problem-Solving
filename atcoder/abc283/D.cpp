/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Scope

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
    stack<char> stk;
    vector<int> cnt(26);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            stk.push(s[i]);
            continue;
        }
        if (isalpha(s[i])) {
            stk.push(s[i]);
            cnt[s[i] - 'a']++;
            if (cnt[s[i] - 'a'] > 1) {
                cout << "No" << nl;
                return;
            }
            continue;
        }
        while (stk.top() != '(') {
            cnt[stk.top() - 'a']--;
            stk.pop();
        }
        stk.pop();
    }
    cout << "Yes" << nl;
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