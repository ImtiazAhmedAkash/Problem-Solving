/*  In the name of ALLAH, the most gracious, the most merciful  */

// Increasing Arrays

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cout << #x << " = " << x << nl

/*
 * If an array element (arr[i]) is less than its previous element (arr[i - 1]),
 * make arr[i] equal to arr[i - 1]. To do that,
 * calculate the difference in 'sum' and assign the arr[i - 1] in arr[i].
 * This assignment is important because, in the next step,
 * arr[i] will be compared with arr[i + 1], with the new value of arr[i].
 * The value of sum is the answer.
 */

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int arr[n];

    ll sum = 0;
    cin >> arr[0];
    for (int i = 1; i < n; i++)
    {
        cin >> arr[i];

        if (arr[i] < arr[i - 1])
        {
            sum += (arr[i - 1] - arr[i]);
            arr[i] = arr[i - 1];
        }
    }

    cout << sum << nl;

    return 0;
}