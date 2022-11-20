// Vanya and Fence

#include <bits/stdc++.h>
using namespace std;

/*
 * The width should be at least 1 per person.
 * So, increment sum by 1 for every input.
 * If an input is greater than the given height, 
 * the width for that person will be 2. 
 * So, in that case, increment sum by 1 again.
 * Finally, the value of sum is the answer.
 */

int main()
{
    int t, width, x, sum = 0;
    cin >> t >> width;

    while (t--)
    {
        cin >> x;
        sum++;

        if (x > width)
            sum++;
    }

    cout << sum << endl;

    return 0;
}