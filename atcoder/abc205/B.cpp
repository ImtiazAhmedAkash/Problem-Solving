/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Permutation Check

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n;
    cin >> n;
    int val;
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> val;
        s.insert(val);
    }
    if (s.size() == n)
        cout << "Yes";
    else
        cout << "No";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}