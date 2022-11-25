// Carrot Cakes
// Credit: https://codeforces.com/profile/chenmark

#include <bits/stdc++.h>
using namespace std;

/*
 * 
 * Check whether or not any cakes remain at time d (time to make the 2nd oven).
 * If any cake remains, then it is reasonable to build the 2nd oven.
 * 
 * To handle cases like 8 6 4 6
 * where, some cakes will remain at time d.
 * But then both of the oven will finish baking them at the same time.
 * The condition in the for loop is current_time <= d.
 */

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t, k, d;
    cin >> n >> t >> k >> d;

    int current_time = 0;

    while (current_time <= d)
    {
        current_time += t;
        n -= k;
    }

    if (n > 0)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}