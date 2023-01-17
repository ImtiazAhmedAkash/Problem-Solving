/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Divisibility Problem

#include <bits/stdc++.h>
using namespace std;

/*
 * The minimum number of moves to make 'a' divisible by 'b' is (b - (a % b)).
 * If a is already divisible by b, then this formula will give b as output. But the accepted result is 0.
 * That's why, (b - (a % b)) is again modded by b.
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        cout << (b - (a % b)) % b << '\n';
    }

    return 0;
}