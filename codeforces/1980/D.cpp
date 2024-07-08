/*  In the Name of ALLAH, the most gracious, the most merciful  */

// GCD-sequence

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 2e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    vector<int> B = {0};
    for (int i = 1; i < n; i++) {
        B.push_back(gcd(A[i], A[i + 1]));
    }
    B.push_back(inf);

    vector<bool> pref(n + 1), suff(n + 2);
    pref[0] = true;
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] & (B[i - 1] <= B[i]);
    }

    suff[n + 1] = suff[n] = true;
    for (int i = n - 1; i >= 0; i--) {
        suff[i] = suff[i + 1] & (B[i] <= B[i + 1]);
    }

    if (pref[n - 2] || suff[2]) {
        cout << "YES" << nl;
        return;
    }

    for (int i = 1; i < n - 1; i++) {
        int g = gcd(A[i], A[i + 2]);
        if (pref[i - 1] && suff[i + 2] && B[i - 1] <= g && g <= B[i + 2]) {
            cout << "YES" << nl;
            return;
        }
    }
    cout << "NO" << nl;
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