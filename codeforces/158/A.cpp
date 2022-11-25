// Next Round

#include <bits/stdc++.h>
using namespace std;

/*
 * Take the input in an (1-indexed) array.
 * If an element is positive (arr[i] > 0) and greater or equal to arr[k], count.
 * Print the count.
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    int arr[n + 1];

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    int count = 0;

    for (int i = 1; i <= n; i++)
    {
        if (arr[i] > 0 && arr[i] >= arr[k])
            count++;
    }

    cout << count << '\n';

    return 0;
}