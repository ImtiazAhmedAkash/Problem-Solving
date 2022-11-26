// Tram

#include <bits/stdc++.h>
using namespace std;

/*
 * There are 't' number of tram's stops.
 * For each stop, 'a' number of passengers get down and 'b' number of passengers get in.
 * The answer is  the maximum number of passengers travelling together.
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    int best = 0, sum = 0;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        sum += (b - a);
        best = max(best, sum);
    }

    cout << best << '\n';

    return 0;
}