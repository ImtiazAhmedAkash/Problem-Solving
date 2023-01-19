/*  In the name of ALLAH, the most gracious, the most merciful  */

// Funny Permutation

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
 * Two conditions must be met for the permutations.
 * 1. For each element X, at least one of its neighbors has a value that differs from the value of X by one.
 * 2. The permutation must have no fixed points. That means for every value X, X != its position.
 *
 * If n is 3, there is no answer.
 * If n is even, print the value from 1 to n in reverse. X will not be same as its position in this case.
 * If n is odd, print the (n / 2) values from n in reverse. Then, print 1 to rest in ascending order.
 *
 * If n = 5, it will print 5, 4, 1, 2, 3. In this way, both of the conditions will be satisfied.
 */

void solve() {
    ll n;
    cin >> n;

    if (n == 3) {
        cout << -1 << '\n';
        return;
    }

    if (n & 1)  // n is odd
    {
        int limit = n / 2;
        for (int i = 1; i <= limit; i++)
            cout << n-- << ' ';

        for (int i = 1; i <= n; i++)
            cout << i << ' ';
    } else {
        for (int i = n; i >= 1; i--)
            cout << i << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}