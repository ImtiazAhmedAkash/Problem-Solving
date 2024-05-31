/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Sliding Window Minimum

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
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (auto& x : A) cin >> x;

    deque<int> Q;
    for (int i = 0; i < n; i++) {
        while (!Q.empty() && A[Q.back()] > A[i]) {
            Q.pop_back();
        }
        Q.push_back(i);

        if (i + 1 < k) continue;

        while (!Q.empty() && Q.front() <= i - k) {
            Q.pop_front();
        }
        cout << A[Q.front()] << ' ';
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