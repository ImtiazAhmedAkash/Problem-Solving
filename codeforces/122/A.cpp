/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Lucky Division

#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define deb(x) cout << #x << " = " << x << nl

/*
 * A lucky number is only consists of 4 and 7.
 * If the divisor of a number is a lucky number, it is called an almost lucky number.
 *
 * So, for every number, check if any of its divisor is a lucky number.
 * If any of them is a lucky number, print "YES", otherwise, "NO".
 *
 * Here, the loop starts from 4, because 1, 2, 3 are not lucky numbers.
 *
 * In the check function, if any number has any digit other than 4 and 7,
 * the function will return false. Otherwise, it will return true.
 */

bool check(int val) {
    while (val != 0) {
        if (val % 10 != 4 && val % 10 != 7)
            return false;
        val /= 10;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 4; i <= n; i++) {
        if (n % i == 0 && check(i)) {
            cout << "YES" << nl;
            return 0;
        }
    }
    cout << "NO" << nl;

    return 0;
}