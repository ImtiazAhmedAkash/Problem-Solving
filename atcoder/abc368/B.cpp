/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Decrease 2 max elements

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
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }

    int ans = 0;
    while (pq.size() >= 2) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        if (a > 1) {
            pq.push(a - 1);
        }
        if (b > 1) {
            pq.push(b - 1);
        }
        ans++;
    }

    cout << ans << nl;
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