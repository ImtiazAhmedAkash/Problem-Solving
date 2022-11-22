// Night at the Museum

#include <bits/stdc++.h>
using namespace std;

#define min(a, b) ((a < b) ? a : b)

/*
 * The letters a-z are placed in a dial (in a circular way).
 * For each letter of the string, find out the minimum step
 * needed to go to a letter from the previous letter.
 * Initially, the dial will be on the letter 'a'.
 * Sum of all the minimum characters will be the answer.
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;

    int sum = min(abs(str[0] - 'a'), 26 - abs(str[0] - 'a'));

    for (int i = 1; i < str.size(); i++)
        sum += min(abs(str[i] - str[i - 1]), 26 - abs(str[i] - str[i - 1]));

    cout << sum << "\n";

    return 0;
}