/*  In the name of ALLAH, the most gracious, the most merciful  */

// Password

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cout << #x << " = " << x << '\n'

/*
 * The value of n is important, the n different integers are of no use.
 * As n integers were not in the password, (10 - n) integers were possibly there.
 * 
 * Find out how many combinations are there with 2 numbers out of (10 - n).
 * As the password is in the form AABB, (two different integers, both were twice), 
 * The permutation for this form is = 4! / (2! * 2!) = 6.
 * Multiply the number of combinations by 6 to find the answer.
 */

ll ncr(ll n, ll r) {
    ll res = 1;
    for (int i = 0; i < r; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

ll solve() {
    int n;
    cin >> n;
    int val;
    int a = 10 - n;

    while (n--)
        cin >> val;

    int ans = 6 * ncr(a, 2);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        cout << solve() << nl;

    return 0;
}