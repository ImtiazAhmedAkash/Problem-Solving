/*  In the Name of ALLAH, the most gracious, the most merciful  */

// LOWER

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define N 200005
#define deb(x) cerr << #x << " = " << x << nl
const ll mod = 998244353;

void solve() {
    int n, q;
    string s;
    cin >> n >> s >> q;
    s = '.' + s;
    set<int> a;
    for (int i = 1; i <= n; i++) a.insert(i);
    int Case = 0;
    while (q--) {
        int t, x;
        char c;
        cin >> t >> x >> c;
        if (t == 1) {
            s[x] = c;
            a.insert(x);
            continue;
        }
        a.clear();
        if (t == 2) Case = -1;
        else Case = 1;
    }
    
    if (Case == 1) {
        for (int i = 1; i <= n; i++) {
            if (a.find(i) == a.end()) s[i] = toupper(s[i]);
        }
    } else if (Case == -1) {
        for (int i = 1; i <= n; i++) {
            if (a.find(i) == a.end()) s[i] = tolower(s[i]);
        }
    }
    cout << string(s.begin() + 1, s.end()) << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}