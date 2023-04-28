/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Amusing Joke

#include <bits/stdc++.h>
using namespace std;

string solve() {
    string a, b, c, res;
    cin >> a >> b >> c;

    /*
     * Merge the first two strings together.
     * Sort the merged string and the third string.
     * After sorting, 
     * If two strings are equal, the answer is "YES", otherwise "NO".
     */

    res = a + b;
    sort(c.begin(), c.end());
    sort(res.begin(), res.end());

    if (c == res)
        return "YES";
    return "NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << solve() << '\n';

    return 0;
}