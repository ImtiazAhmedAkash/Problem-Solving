/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Daydream

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = (1 << 30);
const ll INF = (1LL << 62);
const int mod = 998244353;
const int N = 1e7 + 5;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = n - 1; i >= 0;) {
        string t = "";
        while (t.size() < 5 && i >= 0) {
            t += s[i--];
        }
        if (t == "maerd" || t == "esare") continue;
        while (t.size() < 6 && i >= 0) {
            t += s[i--];
        }
        if (t == "resare") continue;
        while (t.size() < 7 && i >= 0) {
            t += s[i--];
        }
        if (t == "remaerd") continue;
        cout << "NO" << nl;
        return;
    }
    cout << "YES" << nl;
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