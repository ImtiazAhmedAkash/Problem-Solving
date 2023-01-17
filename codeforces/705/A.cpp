/*  In the name of ALLAH, the most gracious, the most merciful   */

// Hulk

#include <bits/stdc++.h>
using namespace std;

/*
 * For every odd value of i, print "I hate " and for every even value, "I love "
 * If (i == n) i.e. the ending statement, print "it" or else print "that "
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        if (i & 1 == 1)
            cout << "I hate ";
        else
            cout << "I love ";

        if (i == n)
            cout << "it";
        else
            cout << "that ";
    }

    cout << '\n';

    return 0;
}