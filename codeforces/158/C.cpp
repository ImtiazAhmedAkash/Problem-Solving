/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Cd and pwd commands

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
    vector<string> A;
    while (n--) {
        string s;
        cin >> s;
        if (s == "cd") {
            string t;
            cin >> t;
            if (t.front() == '/') A.clear();
            stringstream ss(t);
            string tmp;
            while (getline(ss, tmp, '/')) {
                if (tmp == "..") {
                    A.pop_back();
                } else if (!tmp.empty()) {
                    A.push_back(tmp);
                }
            }
        } else {
            for (auto x : A) {
                cout << '/' << x;
            }
            cout << '/' << nl;
        }
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