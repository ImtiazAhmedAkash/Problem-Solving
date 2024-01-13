/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Partitioning the Array

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
    for (int i = 1; i <= n; i++) cin >> A[i];

    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (n % i) continue;

        bool ok = true;
        int Gcd = 0;
        for (int x = 1; x <= i; x++) {
            vector<int> B;
            for (int j = x; j <= n; j += i) {
                B.push_back(A[j]);
            }
            for (int j = 1; j < B.size(); j++) {
                Gcd = gcd(Gcd, abs(B[j] - B[j - 1]));
            }
            if (Gcd == 1) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans++;
        }
    }
    cout << ans << nl;
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