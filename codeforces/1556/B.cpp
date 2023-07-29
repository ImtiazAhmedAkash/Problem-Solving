/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Take Your Places

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1LL << 62)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int even = 0, odd = 0;
    for (auto &x : a) {
        cin >> x;
        if (x & 1) odd++;
        else even++;
    }

    if (abs(odd - even) > 1) {
        cout << -1 << nl;
        return;
    }

    ll ans = INF;
    
    // This loop checks two cases.
    // 1. The first number is odd
    // 2. The first number is even
    for (auto parity : {0, 1}) {
        ll tmp = 0;
        even = odd = -1;
        auto b = a;
        
        // Find the index of the first even number and the first odd number
        for (int i = 0; i < n; i++) {
            if (even == -1 && a[i] % 2 == 0)
                even = i;
            else if (odd == -1 && (a[i] & 1))
                odd = i;
        }
        
        for (int i = 0; i < n; i++) {
            if (b[i] % 2 != parity) {
                int indx;
                if (parity == 0) {
                    indx = even;
                    odd++;
                } else {
                    indx = odd;
                    even++;
                }
                if (indx < i || indx > n) {
                    tmp = INF;
                    break;
                }
                tmp += indx - i;
                swap(b[indx], b[i]);
            }
            // If the current value is even, find the index of the next even number
            // if the current value is odd, find the index of the next odd number
            if (parity == 0) {
                int start = even + 1;
                even = -1;
                for (int j = start; j < n; j++) {
                    if (b[j] % 2 == 0) {
                        even = j;
                        break;
                    }
                }
            } else {
                int start = odd + 1;
                odd = -1;
                for (int j = start; j < n; j++) {
                    if (b[j] & 1) {
                        odd = j;
                        break;
                    }
                }
            }
            parity = !parity;
        }
        ans = min(ans, tmp);
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}