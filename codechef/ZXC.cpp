/*  In the Name of ALLAH, the most gracious, the most merciful  */

// ZXC - Chef Loves Beautiful Strings (Easy Version)

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
    string s;
    cin >> s;

    priority_queue<int> pq;

    for (int i = 0; i < n;) {
        int j = i;
        int cnt = 0;
        while (j < n && s[i] == s[j]) {
            cnt++, j++;
        }
        pq.push(cnt);
        i = j;
    }

    ll ans = 0;
    while (pq.size() > 1) {
        int x = pq.top();
        pq.pop();
        if (x - 1 > 0) {
            pq.push(x - 1);
        }
        ans += pq.size() - 1;
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