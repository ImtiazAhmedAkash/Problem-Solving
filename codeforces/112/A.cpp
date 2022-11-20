// Petya and Strings

#include <bits/stdc++.h>
using namespace std;

/*
 * Transform the given string into lowercase letters.
 * Then compare the strings.
 * If both strings are the same, print 0.
 * If the first string is greater (in ASCII Value), print 1.
 * else print -1.
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);

    if (a == b)
        cout << 0;
    else if (a > b)
        cout << 1;
    else
        cout << -1;

    return 0;
}

/*
 * Another accepted solution:
 * 
 * char a[101], b[101];
 * cin >> a >> b;
 * int x = (strcasecmp(a, b) > 0) ? 1 : (strcasecmp(a, b) < 0) ? -1 : 0;
 * cout << x;
 *
 * strcasecmp() compare two string irrespective of their cases
 * and return the difference of the ASCII value of string a - string b
 */
