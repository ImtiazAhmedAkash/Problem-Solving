/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Lucky Chains

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e7;

vector<int> spf(N + 5);
void precalculate() {
    iota(spf.begin(), spf.end(), 0);
    for (int i = 2; i <= N; i++) {
        if (spf[i] == i) {
            for (int j = i; j <= N; j += i) {
                spf[j] = min(spf[j], i);
            }
        }
    }
}

vector<int> get_prime(int n) {
    vector<int> pf;
    while (n != 1) {
        if (pf.empty() || pf.back() != spf[n]) {
            pf.push_back(spf[n]);
        }
        n /= spf[n];
    }
    return pf;
}

void solve() {
    int a, b;
    cin >> a >> b;

    if (gcd(a, b) != 1) {
        cout << 0 << nl;
        return;
    }

    if (a + 1 == b) {
        cout << -1 << nl;
        return;
    }

    int diff = b - a;
    vector<int> pf = get_prime(diff);

    int next_multiple = inf;
    for (auto &x : pf) {
        int cur = ((a + x - 1) / x) * x;
        next_multiple = min(cur, next_multiple);
    }

    cout << next_multiple - a << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    precalculate();

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}