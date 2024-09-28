/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Least Prefix Sum

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n + 1);
    ll msum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        if (i <= m) {
            msum += A[i];
        }
    }

    priority_queue<int> pq;
    pq.push(A[m]);
    ll sum = msum;
    int ans = 0;
    for (int i = m - 1; i > 0; i--) {
        sum -= A[i + 1];
        while (!pq.empty() && sum < msum) {
            int x = pq.top();
            pq.pop();
            msum -= 2LL * x;
            ans++;
        }
        pq.push(A[i]);
    }

    min_heap<int> mq;
    sum = msum;
    for (int i = m + 1; i <= n; i++) {
        mq.push(A[i]);
        sum += A[i];
        while (!mq.empty() && sum < msum) {
            int x = mq.top();
            mq.pop();
            sum -= 2LL * x;
            ans++;
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