// Crossmarket

#include <bits/stdc++.h>
using namespace std;

/*
 * For a n x m matrix, the minimum steps needed to complete
 * the mentioned teleportaion is 2 * min(n, m) + max (n, m) - 2.
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

        int x = max(n, m);
        int y = min(n, m);

        if (x + y == 2)
            cout << 0 << "\n";
        else
            cout << 2 * y + x - 2 << "\n";
    }

    return 0;
}
