/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Rotate Colored Subsequence

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define N 200005
#define deb(x) cerr << #x << " = " << x << nl
const ll mod = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    vector<deque<char>> a(N);
    vector<int> col(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        col[i] = x;
        a[x].push_back(s[i]);
    }

    for (int i = 1; i <= m; i++) {
        a[i].push_front(a[i].back());
        a[i].pop_back();
    }

    for (int i = 0; i < n; i++) {
        int color = col[i];
        cout << a[color].front();
        a[color].pop_front();
    }
    cout << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}