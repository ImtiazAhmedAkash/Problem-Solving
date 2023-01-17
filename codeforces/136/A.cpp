// Presents
// Credit: https://codeforces.com/profile/tanus_era

#include <bits/stdc++.h>
using namespace std;

/*
 * The array will be indexing from 1, thats why the array is arr[n + 1]
 *
 * First Input:     2           3           4           1
 *              (index 1)   (index 2)   (index 3)   (index 4)
 * This means
 * Friend no. 1 (index) gave presents to friend no. 2 (value), Friend no. 2 gave presents to friend no 3,
 * Friend 3 gave presents to friend 4 and Friend 4 gave presents to friend 1.
 *
 * The task is to print who gave presents to friend 1 to friend n serially.
 * In short, interchange the index and values, store in an ascending order and print them.
 *
 * One efficient way of doing this is, to take a value inside a loop,
 * and for every value, store the index in the value-th index of an array
 * i.e. arr[value] = i (i is the iteration of the loop or the index).
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int arr[n + 1];

    for (int i = 1; i <= n; i++)
    {
        int val;
        cin >> val;
        arr[val] = i;
    }

    for (int i = 1; i <= n; i++)
        cout << arr[i] << ' ';

    cout << '\n';

    return 0;
}