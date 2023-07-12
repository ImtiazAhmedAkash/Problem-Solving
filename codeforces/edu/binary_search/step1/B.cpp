/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Closest to the Left

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    while (k--) {
        int x;
        cin >> x;
        int lo = 0, hi = n;
        int cnt = 0;
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            if (a[mid] > x) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        cout << lo << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}