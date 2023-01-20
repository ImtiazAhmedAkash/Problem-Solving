/*  In the Name of ALLAH, the most gracious, the most merciful  */

// HQ9+

#include <bits/stdc++.h>
using namespace std;

/*
 * If any character of a string is equal to 'H', 'Q' or '9' (case sensitive), the program will produce an output. Hence, return "YES".
 * If the string doesn't contain any of the above three characters, it won't print any output. Hence, return "NO".
 * '+' doesn't produce any output. It only increments value.
 */

string solve() {
    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'H' || str[i] == 'Q' || str[i] == '9')
            return "YES";
    }
    return "NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << solve() << '\n';

    return 0;
}