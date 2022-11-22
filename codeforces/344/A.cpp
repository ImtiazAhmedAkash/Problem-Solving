// Magnets

#include <bits/stdc++.h>
using namespace std;

/*
 * Find out the number of comparison such that 
 * two adjacent elements are not equal.
 * The answer is (total comparison + 1).
 * Because for n comparison, we compare (n + 1) values.
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int arr[n];

    int cnt = 1;
    cin >> arr[0];
    for (int i = 1; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] != arr[i - 1])
            cnt++;
    }

    cout << cnt << '\n';

    return 0;
}