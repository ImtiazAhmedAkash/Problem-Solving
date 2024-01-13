/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Quiz Master

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e5;

vector D(N + 5, vector<int>());

void sieve() {
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            D[j].push_back(i);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    sort(A.begin(), A.end());
    vector<int> cnt(m + 1);
    int ans = inf, cur = 0;
    for (int l = 0, r = 0; r < n; r++) {
        for (auto x : D[A[r]]) {
            if (m < x) break;
            cnt[x]++;
            if (cnt[x] == 1) cur++;
        }
        while (l <= r && m <= cur) {
            ans = min(ans, A[r] - A[l]);
            for (auto x : D[A[l]]) {
                if (m < x) break;
                cnt[x]--;
                if (cnt[x] == 0) cur--;
            }
            l++;
        }
    }
    cout << (ans == inf ? -1 : ans) << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    sieve();

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}