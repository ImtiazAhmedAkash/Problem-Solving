/*  In the Name of ALLAH, the most gracious, the most merciful  */

// World Tour Finals

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
    int n, m;
    cin >> n >> m;
    vector<int> point(m);
    for (auto &x : point) cin >> x;
    vector<string> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    vector<int> player(n);
    iota(player.begin(), player.end(), 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == 'o') player[i] += point[j];
        }
    }
    multiset<int> ms(player.begin(), player.end());
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ms.erase(ms.find(player[i]));
        vector<int> B;
        for (int j = 0; j < m; j++) {
            if (A[i][j] == 'x') B.push_back(point[j]);
        }
        sort(B.begin(), B.end(), greater<int>());
        int need = 0, maxi = *(ms.rbegin()), cur = player[i];
        for (auto x : B) {
            if (cur > maxi) break;
            cur += x;
            need++;
        }
        ans[i] = need;
        ms.insert(player[i]);
    }
    for (auto x : ans) cout << x << nl;
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