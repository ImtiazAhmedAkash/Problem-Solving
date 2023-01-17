/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Arrival of the General

#include <bits/stdc++.h>
using namespace std;

/*
 * The maximum value needs be moved to the 0 index
 * and the minimum needs will be moved to the n - 1 index. The soldiers can move only one index at one step.
 *
 * So, first find the first position of the max element (important if the max is present twice).
 * That's why only greater than sign is used (not greater than equal).
 * and the last position of the min element. Because the max will be at the front and the min will be at the back.
 * The first position of the max is closest to the front. Similarly, the last position of the min is closent to the back.
 *
 * If the max element is present after min element, then increment the min index by 1.
 * Because when two elements will be swapped to bring the max to the front, the min will move to the next index from its current index.
 *
 * Finally, the answer is the difference between max index and its final index (which is 0 for this problem) +
 * the difference between the min index and its final index (which is n - 1 for this problem).
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int arr[n], maxi = 0, mini = 100, max_index, min_index;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        if (arr[i] > maxi) {
            maxi = arr[i];
            max_index = i;
        }

        if (arr[i] <= mini) {
            mini = arr[i];
            min_index = i;
        }
    }

    if (max_index > min_index)
        min_index++;

    cout << ((max_index - 0) + (n - 1 - min_index)) << '\n';

    return 0;
}