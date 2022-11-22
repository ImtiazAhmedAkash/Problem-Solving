// Black Square

#include <bits/stdc++.h>
using namespace std;

/*
 * Calories for each strip is given sequentially.
 * First store those calories in 1-indexed array, 
 * so that array index matches with the strip number.
 *
 * Take the given string in a string.
 * For each character of the string, convert it into a integer.
 * The integer represents the string number.
 * And take the sum of arr[strip number].
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a[5];
    a[0] = 0;

    for (int i = 1; i < 5; i++)
        cin >> a[i];

    string str;
    cin >> str;

    int length = str.length();

    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += a[str[i] - '0'];
    }

    cout << sum << "\n";

    return 0;
}