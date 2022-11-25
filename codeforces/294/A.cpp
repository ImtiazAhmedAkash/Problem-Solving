// Shaass and Oskols

#include <bits/stdc++.h>
using namespace std;

/*
 * Take an array of n + 2 elements.
 * 0 and n + 1 indexes of the array store number of (flown away) birds.
 * So, ignore them while printing the final array.
 *
 * Start counting from index 1 till n.
 * Each time, num-th birds of arr[r] is shot.
 * The number of remaining birds on the left is num - 1.
 * They will move to the upper wire (previous index).
 * So, num - 1 will be added to the previous index.
 *
 * Similary,
 * The number of remaining birds on the right is arr[r] - num.
 * They will move to the lower wire (next index).
 * So, arr[r] - num will be added to the next index.
 *
 * And, there will be no birds left on arr[r].
 * So, assign 0 to arr[0].
 * Repeat this, for number of shots fired.
 *
 * Finally, print the array from index 1 to n.
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int arr[n + 2];

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    int shots;
    cin >> shots;

    while (shots--)
    {
        int r, num;
        cin >> r >> num;

        arr[r - 1] += num - 1;
        arr[r + 1] += arr[r] - num;
        arr[r] = 0;
    }

    for (int i = 1; i <= n; i++)
        cout << arr[i] << "\n";

    return 0;
}