// Beautiful Matrix

#include <bits/stdc++.h>
using namespace std;

/*
 * The required index for a beautiful matrix is (2, 2).
 * Search for 1 in the matrix.
 * Take the distance of index (2, 2) from 1's index.
 * The distance is abs(i - 2) + abs (j - 2).
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[5][5], result;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 1)
            {
                result = abs(i - 2) + abs(j - 2);
            }
        }
    }

    cout << result << "\n";

    return 0;
}