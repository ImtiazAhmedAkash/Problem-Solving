// Domino Piling

#include <bits/stdc++.h>
using namespace std;

/*
 * Output is area of the rectangle (m * n) divided by area of a domino (2 * 1).
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    cout << (m * n / 2) << '\n';

    return 0;
}