/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Cat Cycle

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

/*
 * The cats spots will collide if and only if n is odd.
 * They will meet at every ((n / 2) + 1)-th hour.
 * In the time of collision, the B-cat's position is increased by 1.
 * So, the k-th hour (when n is odd) will be the same as (k + ((k - 1)/(n - 2)))-th hour (when n is even).
 * 
 * Then, calculate (k % n), if (k == n), the mod value will be 0.
 * That is, if ans becomes zero, the B-cat is in n-th spot.
 */

void solve() {
    int n, k;
    cin >> n >> k;
    int ans;
    if (n & 1) {
        k += ((k - 1) / (n / 2));
    }
    ans = k % n;
    if (ans == 0) ans = n;
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}