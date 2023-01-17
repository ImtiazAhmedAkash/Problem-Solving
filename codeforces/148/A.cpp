/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Credit: https://codeforces.com/profile/YouKn0wWho
// Insomnia Cure

#include <bits/stdc++.h>
using namespace std;

/*
 * Iterate from 1 to d. If a number is divided by any of (k, l, m, n), count.
 * That many dragon will take some kind of damage (moral or physical). Finally, print count.
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;

    int cnt = 0;
    for (int i = 1; i <= d; i++) {
        if ((i % k == 0) || (i % l == 0) || (i % m == 0) || (i % n == 0))
            cnt++;
    }

    cout << cnt << '\n';

    return 0;
}