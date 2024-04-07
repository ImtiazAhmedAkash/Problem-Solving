/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 11029 - Leading and Trailing

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 1000;
const int N = 2e5 + 5;

int power(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = 1LL * ans * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;

    auto format = [&](int x) -> string {
        string s = to_string(x);
        while (s.size() < 3) {
            s.insert(s.begin(), '0');
        }
        return s;
    };

    // First 3 digit
    double p = k * log10(n);
    p -= floor(p);
    double x = pow(10, p);
    int fst = floor(x * 100);

    // Last 3 digit
    int lst = power(n, k);

    cout << fst << "..." << format(lst) << nl;
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