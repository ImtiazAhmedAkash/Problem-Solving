/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Pangram

#include <bits/stdc++.h>
using namespace std;

/*
 * Take input character by character.
 * Then, convert it into a lowercase letter and insert into a set.
 * After taking all the input, if the set has 26 elements, (i.e. 26 letters), print "YES", else "NO".
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    set<char> s;

    while (t--) {
        char a;
        cin >> a;

        a = tolower(a);
        s.insert(a);
    }

    if (s.size() == 26)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';

    return 0;
}