/*  In the name of ALLAH, the most gracious, the most merciful  */

// Death's Blessing

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cout << #x << " = " << x << '\n'

/*
 * It doesn't matter what order you choose to kill the monster, 
 * their initial health will be included in the total time.
 * So, first of all, sum up all of their initial health.
 * 
 * Now, if you kill a monster, it's left and right neighbour will be casted by its spell.
 * So, in order to to kill them in minimum time, the optimal way would be to
 * kill either the leftmost or rightmost monster first, so that only one monster is affected by the spell.
 * Kill the monster will the maximum curse or spell last, so that no other monster is afftected by the spell.
 * 
 * That's why, while taking the spell value as input, add all of the inputs and calculate the maximum curse.
 * And finally subtract the maximum curse from the answer to get the final answer.
 */

void solve() {
    int n;
    cin >> n;

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        ans += x;
    }

    ll curse = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        ans += x;
        curse = max(curse, x);
    }

    cout << ans - curse << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}