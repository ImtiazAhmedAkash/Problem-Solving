/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Permutation Game

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
    int n, k, b, s;
    cin >> n >> k >> b >> s;
    vector<int> P(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> P[i];
    }
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    auto calculate = [&](int pos) -> ll {
        vector<bool> used(n + 1, false);
        ll ans = 0;
        ll sum = 0;
        for (int i = 1; i <= k && !used[pos]; i++) {
            sum += A[pos];
            ans = max(ans, sum + 1LL * (k - i) * A[pos]);
            used[pos] = true;
            pos = P[pos];
        }
        return ans;
    };

    ll bodya = calculate(b);
    ll sasha = calculate(s);
    if (bodya == sasha) {
        cout << "Draw" << nl;
    } else {
        cout << (bodya < sasha ? "Sasha" : "Bodya") << nl;
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