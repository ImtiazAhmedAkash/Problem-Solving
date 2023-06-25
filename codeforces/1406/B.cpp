/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Maximum Product

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1LL << 62)
#define mod 998244353
#define N 200005
#define deb(x) cerr << #x << " = " << x << nl

/*
 * Take the negative and non-negative numbers in two separate vector.
 * If there are no non-negative numbers in the input, the answer will be negative.
 * The answer will be the product of the 5 biggest negative number. (Note: -1 > -10).
 * Otherwise, the answer will be positive.
 * 
 * Now, sort the non-negative numbers in descending order.
 * If there are no non-negative numbers, sort the negative numbers in descending order.
 * Otherwise, sort them in ascending order.
 * 
 * Now, take different combinations of negative and non-negative numbers and calculate their product.
 * The maximum of the product is the answer.
 */

void solve() {
    int n;
    cin >> n;
    vector<ll> pos, neg;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (x < 0) neg.push_back(x);
        else pos.push_back(x);
    }

    sort(pos.begin(), pos.end(), greater<ll>());
    if (pos.size()) sort(neg.begin(), neg.end());
    else sort(neg.begin(), neg.end(), greater<ll>());

    ll ans = -INF;
    for (int i = 0; i <= 5; i++) {
        if (neg.size() >= i && pos.size() >= (5 - i)) {
            ll tmp = 1;
            for (int j = 0; j < i; j++) tmp *= neg[j];
            for (int j = 0; j < 5 - i; j++) tmp *= pos[j];
            ans = max(ans, tmp);
        }
    }

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