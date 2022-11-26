// Translation

#include <bits/stdc++.h>
using namespace std;

/*
 * Reverse one of the string.
 * Then compare them.
 * If the strings are same, print "YES".
 * Otherwise, print "NO".
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    reverse(b.begin(), b.end());

    cout << ((a == b) ? "YES" : "NO") << '\n';

    return 0;
}