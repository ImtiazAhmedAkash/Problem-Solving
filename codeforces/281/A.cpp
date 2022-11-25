// Word Capitalization

#include <bits/stdc++.h>
using namespace std;

/*
 * If the first letter (str[0]) is small letter, make it capital.
 * Then print the string.
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;

    str[0] = toupper(str[0]);
    cout << str;

    return 0;
}