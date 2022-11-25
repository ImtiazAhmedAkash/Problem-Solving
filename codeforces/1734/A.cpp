// Select Three Sticks (Contest)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * Take all the stick lengths in an array.
 * Sort the array in ascending order.
 * Use a for loop from index 1 to n - 2,
 * and find out the minimum steps of (arr[i + 1] - arr[i - 1]).
 * For the first test case: 1 2 3
 * The minimum step = (2 - 1) + (3 - 2) = 2
 * which can be written as (3 - 2 + 2 - 1) = (3 - 1) = 2
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        sort(arr, arr + n);

        ll steps = 1e10;

        for (int i = 1; i < n - 1; i++)
        {
            steps = min(steps, (arr[i + 1] - arr[i - 1]));
        }

        cout << steps << '\n';
    }

    return 0;
}