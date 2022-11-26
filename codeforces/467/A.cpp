// George and Accomodation

#include <bits/stdc++.h>
using namespace std;

/*
 * p is the number of people living in a room, and q is the maximum capacity.
 * If there are at least two empty space in a room, George and his friend can stay together.
 * If (p + 2) <= q (total capacity), they can stay in the same room.
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    int count = 0;
    while (t--)
    {
        int p, q;
        cin >> p >> q;

        if (p + 2 <= q)
            count++;
    }

    cout << count << '\n';

    return 0;
}