/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// C - Minimum Glutton

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
    ll x, y;
    cin >> n >> x >> y;
    vector<ll> A(n);
    for (auto &x : A) cin >> x;
    vector<ll> B(n);
    for (auto &x : B) cin >> x;
    
    sort(A.begin(), A.end(), greater());
    sort(B.begin(), B.end(), greater());
    
    int ans = n;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
        if (x < sum) {
            ans = min(ans, i + 1);
        }
    }
    
    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += B[i];
        if (y < sum) {
            ans = min(ans, i + 1);
        }
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