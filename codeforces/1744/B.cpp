/*  In the name of ALLAH, the most gracious, the most merciful  */

// Even Odd Increment

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define deb(x) cout << #x << " " << x << '\n'

/*
 * Calculate the sum of all values and count the number of even and odd elements while taking them as input.
 * 
 * If an odd value is added, an odd value becomes even and an even value becomes odd.
 * odd value + odd value = even value
 * even value + odd value  = odd value
 * 
 * If an even value is added, an odd value remains odd, and an even value remains even.
 * odd value + even value = odd value
 * even value + even value = even value
 * 
 * So, whenever an odd value is added, when (op == 0), the even values becomes odd values. 
 * That is why, odd count is increased by even count (odd += even) and even count resets to zero.
 * Similary, the opposite happens when (op == 1).
 * 
 * In every operation for op, update the sum.
 * Finally, print the sum.
 */

void solve() {
    ll n, q;
    cin >> n >> q;

    ll odd = 0, even = 0, sum = 0;

    ll val;
    for (ll i = 0; i < n; i++) {
        cin >> val;
        sum += val;

        if (val & 1) odd++;
        else even++;
    }

    ll op, a;
    while (q--) {
        cin >> op >> a;

        if (op) {
            sum += (odd * a);
            if (a & 1) {
                even += odd;
                odd = 0;
            }
        } 
        else {
            sum += (even * a);
            if (a & 1) {
                odd += even;
                even = 0;
            }
        }

        cout << sum << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}