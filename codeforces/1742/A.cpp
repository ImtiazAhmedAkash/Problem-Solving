/*  In the name of ALLAH, the most gracious, the most merciful  */

// Sum

#include <bits/stdc++.h>
using namespace std;

/*
 * Take three inputs in an array. Sort them in descending order.
 * If the first element of the array is equal to the sum of the other two elements, 
 * Print "YES". Otherwise, print "NO".
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    int arr[3];
    while (t--) {
        cin >> arr[0] >> arr[1] >> arr[2];

        sort(arr, arr + 3, greater<int>());

        if (arr[0] == (arr[1] + arr[2]))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}