/*  In the Name of ALLAH, the most gracious, the most merciful  */

// The Humanoid

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
    int n, h;
    cin >> n >> h;
    vector<int> A(n);
    for (auto& x : A) cin >> x;

    sort(A.begin(), A.end());

    vector<int> B = {2, 2, 3};

    int ans = 0;
    do {
        auto P = B;
        int cur = 0;
        ll health = h;
        for (int i = 0; i < n; i++) {
            while (A[i] >= health && !P.empty()) {
                health *= P.back();
                P.pop_back();
            }

            if (A[i] < health) {
                health += A[i] / 2;
                cur++;
            } else {
                break;
            }
        }
        ans = max(ans, cur);
    } while (next_permutation(B.begin(), B.end()));

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