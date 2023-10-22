/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Printing Machine

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
    vector<pair<ll, ll>> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i].first >> A[i].second;
        A[i].second += A[i].first;
    }
    sort(A.begin(), A.end());
    int i = 0, ans = 0;
    ll time = 1;
    priority_queue<ll, vector<ll>, greater<ll>> PQ;
    while (true) {
        if (PQ.empty()) {
            if (i == n) break;
            time = max(time, A[i].first);
        }
        while (i < n && A[i].first <= time) {
            PQ.push(A[i].second);
            i++;
        }
        while (!PQ.empty() && PQ.top() < time) {
            PQ.pop();
        }
        if (!PQ.empty()) {
            PQ.pop();
            ans++;
        }
        time++;
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