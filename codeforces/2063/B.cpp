/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Subsequence Update

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
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    priority_queue<int> pq;
    for (int i = l; i <= r; i++) {
        pq.push(A[i]);
    }
    for (int i = 1; i < l; i++) {
        if (A[i] < pq.top()) {
            pq.pop();
            pq.push(A[i]);
        }
    }
    
    ll ans = INF;
    ll cur = 0;
    while (!pq.empty()) {
        cur += pq.top();
        pq.pop();
    }
    ans = min(ans, cur);
    
    for (int i = l; i <= r; i++) {
        pq.push(A[i]);
    }
    for (int i = r + 1; i <= n; i++) {
        if (A[i] < pq.top()) {
            pq.pop();
            pq.push(A[i]);
        }
    }
    
    cur = 0;
    while (!pq.empty()) {
        cur += pq.top();
        pq.pop();
    }
    ans = min(ans, cur);
    
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