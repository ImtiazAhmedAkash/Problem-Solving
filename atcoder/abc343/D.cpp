/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Diversity of Scores

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5;

void solve() {
    int n, t;
    cin >> n >> t;
    vector<ll> score(n + 1);
    map<ll, int> M;
    M[0] = n;
    while (t--) {
        int a, b;
        cin >> a >> b;
        M[score[a]]--;
        if (M[score[a]] == 0) {
            M.erase(score[a]);
        }
        score[a] += b;
        M[score[a]]++;
        cout << M.size() << nl;
    }
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