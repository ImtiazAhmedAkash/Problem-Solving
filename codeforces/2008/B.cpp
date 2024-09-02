/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Square or Not

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

    int x = sqrt(n) + 5;
    while (x * x > n) x--;
    if (x * x != n) {
        cout << "No" << nl;
        return;
    }

    vector<string> A;
    int i = 0;
    string t;
    while (i < n) {
        t += s[i];
        i++;
        if (t.size() == x) {
            A.push_back(t);
            t.clear();
        }
    }

    bool ok = true;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            if ((i == 0 || i == x - 1 || j == 0 || j == x - 1)) {
                if (A[i][j] != '1') {
                    ok = false;
                    break;
                }
            } else if (A[i][j] != '0') {
                ok = false;
                break;
            }
        }
    }

    cout << (ok ? "Yes" : "No") << nl;
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