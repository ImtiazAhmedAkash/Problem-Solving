// Way Too Long Words

#include <bits/stdc++.h>
using namespace std;

/*
 * If a string size is greater than 10,
 * print the first element, total characters between the first element and the last element,
 * and the last element.
 * Otherwise, print the string.
 * s.front() -> access the first element (same as s[0]).
 * s.back() -> access the last element (same as s[s.size() - 1]).
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    string s;
    while (t--)
    {
        cin >> s;
        int length = s.size();

        if (length > 10)
            cout << s.front() << length - 2 << s.back() << '\n';
        else
            cout << s << '\n';
    }

    return 0;
}