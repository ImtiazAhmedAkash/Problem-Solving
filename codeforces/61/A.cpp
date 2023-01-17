// Ultra Fast Mathematician

#include <bits/stdc++.h>
using namespace std;

/*
 * Take both numbers as strings as the max length is 100.
 * The size of both of the strings are the same.
 * Iterate from 0 index to less than any one string's size.
 * If the elements (of same index) of both string are the same, print 0. Else print 1.
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i])
            cout << 0;
        else
            cout << 1;
    }

    cout << '\n';

    return 0;
}