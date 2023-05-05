/*  In the name of ALLAH, the most gracious, the most merciful  */

// Cowardly Rooks

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cout << #x << " = " << x << '\n'

/*
 * If the number of rooks is less than the chess board size, 
 * then there would be at least one such square to place a rook such that no two rooks will attack each others.
 */

string solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
    }

    if (m < n)
        return "YES";

    return "NO";
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