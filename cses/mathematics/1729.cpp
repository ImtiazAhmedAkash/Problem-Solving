/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Stick Game

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 100;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> moves(k);
    for (auto &i : moves) cin >> i;
    sort(moves.begin(), moves.end());

    vector<bool> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        bool win = false;
        for (int j = 0; j < k && moves[j] <= i; j++) {
            int state = i - moves[j];
            if (!ans[state]) {
                win = true;
                break;
            }
        }
        ans[i] = win;
    }

    for (int i = 1; i <= n; i++) {
        cout << (ans[i] ? 'W' : 'L');
    }
    cout << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}