// Immobile Knight

#include <bits/stdc++.h>
using namespace std;

/*
 * Only for 2 * 3, 3 * 2 and 3 * 3 boards, 2 2 cell will be isolated.
 * Apart from the above mentioned boards,
 * If there is any isolated cell in a board, 1 1 will be one of them.
 * If there is no isolated cell, any cell is accepted.
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        if (max(m, n) == 3 && ((m + n) == 5 || (m + n) == 6))
            cout << "2 2" << '\n';
        else
            cout << "1 1" << '\n';
    }

    return 0;
}