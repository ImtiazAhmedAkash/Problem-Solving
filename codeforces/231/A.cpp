// Team

#include <bits/stdc++.h>
using namespace std;

/*
 * Take three inputs a, b, c.
 * If the sum is at least 2, increment the count by 1.
 * Repeat this t times.
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, count = 0;
    cin >> t;

    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (a + b + c >= 2)
            count++;
    }

    cout << count << "\n";

    return 0;
}