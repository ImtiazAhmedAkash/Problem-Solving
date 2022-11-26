// Beautiful Year

#include <bits/stdc++.h>
using namespace std;

/*
 * The checking will start from the following year. So, n++.
 * Convert the year (int) into string.
 * Then, we will insert all the characters of the string into a set.
 * As the string element are digit characters, set<int> or set<char> can be used.
 * If the set size is less than 4, increment n by 1 and
 * repeat the process (until set size is 4).
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    n++;

    while (1)
    {
        string str = to_string(n);

        set<int> distinct(str.begin(), str.end());

        if (distinct.size() == 4)
            break;
        n++;
    }
    cout << n;

    return 0;
}