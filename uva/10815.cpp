/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Andy's First Dictionary

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
    set<string> st;
    while (cin >> s) {
        string t = "";
        for (int i = 0; i < s.size(); i++) {
            if (isalpha(s[i])) {
                t += tolower(s[i]);
            }
            if ((!isalpha(s[i]) || i + 1 == s.size()) && !t.empty()) {
                st.insert(t);
                t = "";
            }
        }
    }
    for (auto x : st) {
        cout << x << nl;
    }
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