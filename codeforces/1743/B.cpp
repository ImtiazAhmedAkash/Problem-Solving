/*  In the name of ALLAH, the most gracious, the most merciful  */

// Permutation Value

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cout << #x << " = " << x << '\n'

/*
 * The minimum possible value for a permutaion of size n, is 1.
 * It can be found by separating 1 and 2 as far as possible.
 * That is, placing 1 and 2 on two ends of the array.
 * 
 * For each test case, 
 * one of the possible solution is, 
 * print from 2 to n first, and then print 1 at the end.
 */

void solve() {
    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) cout << i << " ";
    cout << 1 << nl;
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