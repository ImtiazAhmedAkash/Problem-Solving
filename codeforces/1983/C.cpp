/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Have Your Cake and Eat It Too

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
    vector A(3, vector<int>(n + 1));

    ll total = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
            if (i == 0) {
                total += A[i][j];
            }
        }
    }
    total = (total + 2) / 3;

    vector pref(3, vector<ll>(n + 1));
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= n; j++) {
            pref[i][j] = pref[i][j - 1] + A[i][j];
        }
    }

    vector<int> order(3);
    iota(order.begin(), order.end(), 0);

    vector<int> L(3), R(3);
    do {
        int x = order[0];
        int y = order[1];
        int z = order[2];
        L[x] = 1;
        R[x] = lower_bound(pref[x].begin(), pref[x].end(), total) - pref[x].begin();
        L[y] = R[x] + 1;
        R[y] = lower_bound(pref[y].begin(), pref[y].end(), pref[y][L[y] - 1] + total) - pref[y].begin();
        if (R[y] != n + 1) {
            L[z] = R[y] + 1;
            R[z] = n;
            if (pref[z][R[z]] - pref[z][L[z] - 1] >= total) {
                for (int i = 0; i < 3; i++) {
                    cout << L[i] << " " << R[i] << " ";
                }
                cout << nl;
                return;
            }
        }
    } while (next_permutation(order.begin(), order.end()));

    cout << -1 << nl;
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