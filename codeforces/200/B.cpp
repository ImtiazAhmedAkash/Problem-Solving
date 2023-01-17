// Drinks

#include <bits/stdc++.h>
using namespace std;

/*
 * The answer is the average of the given values.
 * 
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, val;
    double sum = 0;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> val;
        sum += val;
    }

    cout << fixed << setprecision(12);
    cout << (sum / t) << '\n';

    return 0;
}