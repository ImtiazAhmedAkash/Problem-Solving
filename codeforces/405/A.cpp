// Gravity Flip

#include <bits/stdc++.h>
using namespace std;

/*
 * Sort the given array and print it.
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}