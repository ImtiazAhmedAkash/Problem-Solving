/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Elections

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
    int n, c;
    cin >> n >> c;
    vector<ll> A(n + 1), pref(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        pref[i] = pref[i - 1] + A[i];
    }

    int indx = max_element(A.begin(), A.end()) - A.begin();
    int mx = A[indx];

    vector<int> B(n + 1);
    for (int i = 1; i <= n; i++) {
        int ans = 0;

        if (i == 1) {
            if (A[i] + c < mx) ans = 1;
            B[i] = ans;
            continue;
        }

        if (A[1] + c < A[i] && (A[i] > mx || (A[i] == mx && i == indx))) {
            B[i] = ans;
            continue;
        }

        ans = i - 1;
        ll cur = pref[i] + c;
        if (cur < mx) ans++;
        B[i] = ans;
    }

    for (int i = 1; i <= n; i++) {
        cout << B[i] << " \n"[i == n];
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