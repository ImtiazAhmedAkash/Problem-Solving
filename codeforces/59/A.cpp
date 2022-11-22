// Word

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;

    int length = str.length();

    int lower = 0, upper = 0;

    // check which case is greater of the two
    for (int i = 0; i < length; i++)
    {
        (str[i] >= 'a' && str[i] <= 'z') ? lower++ : upper++;
    }

    // transform function works like this
    // transform (Iterator inputBegin, Iterator inputEnd,
    //            Iterator OutputBegin, unary_operation)
    if (upper > lower)
        transform(str.begin(), str.end(), str.begin(), ::toupper);
    else
        transform(str.begin(), str.end(), str.begin(), ::tolower);

    cout << str;

    return 0;
}