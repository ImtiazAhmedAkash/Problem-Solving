/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Tea Tasting

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
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    vector<ll> B(n + 1), pref(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
        pref[i] = pref[i - 1] + B[i];
    }

    vector<ll> E(n + 2);
    vector<int> F(n + 2);
    for (int i = 1; i <= n; i++) {
        int indx = upper_bound(pref.begin(), pref.end(), pref[i - 1] + A[i]) - pref.begin();
        if (i < indx) {
            F[i]++;
            F[indx]--;
        }
        if (indx <= n) {
            E[indx] += A[i] - (pref[indx - 1] - pref[i - 1]);
        }
    }

    for (int i = 1; i <= n; i++) {
        F[i] += F[i - 1];
        cout << 1LL * F[i] * B[i] + E[i] << " \n"[i == n];
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