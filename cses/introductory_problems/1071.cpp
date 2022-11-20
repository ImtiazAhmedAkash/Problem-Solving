/*  In the name of ALLAH, the most gracious, the most merciful  */

// Number Spiral

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cout << #x << " = " << x << nl

/*
 * First of all, find the maximum of the col and row.
 * This will determine the order of the matrix.
 *
 * The odd columns of the first row, contains the square of the respective column.
 * The even rows of the first column, contains the square of the respective row.
 *
 * Put the square value of the max in a variable.
 *
 * If mx is odd, calculate value from the column.
 * If mx is odd, calculate value from the row.
 *
 * If mx is odd and row is 1, return the square of the column.
 * else, return res - (the difference of (1, mx) and (row, col)).
 *
 * If mx is even and column is 1, return the square of the row.
 * else, return res - (the difference of (mx, 1) and (row, col)).
 */

long long solve()
{
    ll row, col;
    cin >> row >> col;

    ll mx = max(row, col);
    ll res = mx * mx;

    if (mx & 1)
    {
        if (row == 1)
            return res;

        return res - abs(1 - row) - abs(mx - col);
    }
    else
    {
        if (col == 1)
            return res;

        return res - abs(1 - col) - abs(mx - row);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        cout << solve() << nl;

    return 0;
}