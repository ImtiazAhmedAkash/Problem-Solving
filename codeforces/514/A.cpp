/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Chewbacca and Number

#include <bits/stdc++.h>
using namespace std;

/*
 * Take the input as a string.
 * For every index, take the minimum of str[index] and '9' - str[index] and assign it to the resultant string.
 * min(x, y) function does not work for char, so convert them to int while comparing and then convert them into char.
 * The first digit of the resultant string cannot be zero. So, if res[0] is '0', change it to '9'.
 * Finally, print the resultant string.
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str, res;
    cin >> str;

    for (int i = 0; i < str.size(); i++)
        res += (min(str[i] - '0', '9' - str[i]) + '0');

    if (res[0] == '0')
        res[0] = '9';

    cout << res << '\n';

    return 0;
}