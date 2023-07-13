/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Unexpressed

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

/*
 * First, find out the representable numbers between 1 and N (inclusive) as a^b.
 * where a and b cannot be less than 2.
 * 
 * As, b cannot be less than 2, iterate a loop till the sqare root of n.
 * For every i-th iteration, calculate the value from i^2 to i^x such that i^x <= n,
 * and insert them into a set. Set is used to prevent counting duplicate values more than once.
 * Finally, the unrepresentable numbers will be (total numbers - representable numbers) i.e. (n - s.size()).
 */

void solve() {
    ll n;
    cin >> n;
    set<ll> s;
    for (ll i = 2; i * i <= n; i++) {
        ll val = i * i;
        while (val <= n) {
            s.insert(val);
            val *= i;
        }
    }
    cout << n - s.size() << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}