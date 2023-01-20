/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Young Physicist

#include <bits/stdc++.h>
using namespace std;

/*
 * If resultant force (summation) in each axes / co-ordinate (individually) is zero,
 * The body is in equilibrium. Otherwise, it is not.
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    int xc = 0, yc = 0, zc = 0;
    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;

        xc += x;
        yc += y;
        zc += z;
    }

    if (xc == 0 && yc == 0 && zc == 0)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';

    return 0;
}