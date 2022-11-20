// Bear and Big Brother

#include <bits/stdc++.h>
using namespace std;

/*
 * For each year, Limak's size (x) will be 3 times the previous size
 * and Bob's size (y) will be 2 times the previous size.
 * Iterate a loop until x is greater than y.
 * Count how many times the loop executes.
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y, count = 0;
    cin >> x >> y;

    while (x <= y)
    {
        x *= 3;
        y *= 2;
        count++;
    }

    cout << count << "\n";

    return 0;
}