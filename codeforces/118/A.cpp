/*  In the Name of ALLAH, the most gracious, the most merciful  */

// String Task

#include <bits/stdc++.h>
using namespace std;

/*
 * First of all, convert the letter to lowercase letter one by one.
 * Then if any element is not a vowel (here a, e, i, o, u, y), it is a consonant.
 * Print a dot and the consonant.
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        str[i] = tolower(str[i]);

        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' && str[i] != 'y')
            cout << '.' << (str[i]);
    }

    cout << '\n';

    return 0;
}