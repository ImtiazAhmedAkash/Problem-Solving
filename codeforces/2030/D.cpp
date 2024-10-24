/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// QED's Favorite Permutation

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
    int n, q;
    cin >> n >> q;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    string s;
    cin >> s;
    s = "-" + s;

    vector<int> pref(n + 1);
    pref[1] = A[1];
    for (int i = 2; i <= n; i++) {
        pref[i] = max(A[i], pref[i - 1]);
    }

    vector<int> suff(n + 1);
    suff[n] = A[n];
    for (int i = n - 1; i > 0; i--) {
        suff[i] = min(A[i], suff[i + 1]);
    }

    set<int> bad;
    for (int i = 1; i + 1 <= n; i++) {
        if (s[i] == 'L' && s[i + 1] == 'R' && pref[i] > suff[i + 1]) {
            bad.insert(i);
        }
    }

    while (q--) {
        int i;
        cin >> i;

        if (s[i] == 'L') {
            if (s[i + 1] == 'R' && pref[i] > suff[i + 1]) {
                bad.erase(i);
            }
            s[i] = 'R';
            if (s[i - 1] == 'L' && pref[i - 1] > suff[i]) {
                bad.insert(i - 1);
            }
        } else {
            if (s[i - 1] == 'L' && pref[i - 1] > suff[i]) {
                bad.erase(i - 1);
            }
            s[i] = 'L';
            if (s[i + 1] == 'R' && pref[i] > suff[i + 1]) {
                bad.insert(i);
            }
        }

        cout << (bad.empty() ? "YES" : "NO") << nl;
    }
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