/*  In the Name of ALLAH, the most gracious, the most merciful  */

// JUSTTWO - Double Trouble

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<>>;

int power(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = 1LL * ans * a % mod;
        a = 1LL * a * a % mod;
        b /= 2;
    }
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    min_heap<ll> pq;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        pq.push(x);
    }

    while (k && pq.top() <= inf) {
        ll x = pq.top();
        pq.pop();
        pq.push(2 * x);
        k--;
    }

    vector<ll> A;
    while (!pq.empty()) {
        A.push_back(pq.top());
        pq.pop();
    }

    int d = k / n;
    ll ans = 0;
    for (int i = 0; i < k % n; i++) {
        ans += A[i] * power(2, d + 1) % mod;
        if (ans >= mod) {
            ans -= mod;
        }
    }
    for (int i = k % n; i < n; i++) {
        ans += A[i] * power(2, d) % mod;
        if (ans >= mod) {
            ans -= mod;
        }
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