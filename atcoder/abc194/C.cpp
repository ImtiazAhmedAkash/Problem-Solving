/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Squared Error 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

/*
 * The constraint is -200 <= X <= 200. So, there can be a maximum of 401 distinct values.
 * Check for the distinct elements and store them in a vector.
 * Count the frequency of the elements using a map.
 * 
 * For every value, v[i], count the squared difference for all of its pairs.
 * While counting the difference, multiply the frequency of each elements of a pair and 
 * add them in "ans" in order to count the multiple same pairs.
 * For example: The input can be 2 2 2 3 3 3 3
 * The vector will only have 2 and 3 stored. So, not multiplying the frequencies will give wrong answer.
 * 
 * Finally, Print the "ans".
 */

void solve() {
    int n;
    cin >> n;
    vector<ll> v;
    set<ll> s;
    map<ll, ll> m;
    ll val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        m[val]++;
        if (s.find(val) == s.end()) {
            v.push_back(val);
            s.insert(val);
        }
    }
    ll ans = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            ll x = v[i] - v[j];
            ans += (m[v[i]] * m[v[j]] * x * x);
        }
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}