/*  In the name of ALLAH, the most gracious, the most merciful  */

// Increasing

#include <bits/stdc++.h>
using namespace std;

/*
 * Take the inputs in an array. Sort the array.
 * If any two elements are equal, the array cannot be sorted in strictly increasing order.
 * Hence, print "NO". Otherwise, print "YES".
 */

string solve() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    for (int i = 0; i + 1 < n; i++) {
        if (arr[i] == arr[i + 1])
            return "NO";
    }
    return "YES";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }

    return 0;
}