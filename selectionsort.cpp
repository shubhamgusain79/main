#include <iostream>
#include <vector>
using namespace std;

void selectionSortCount(vector<int> &arr, long long &comparisons, long long &swaps) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            swaps++;
        }
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> arr(n);   

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        long long comparisons = 0;
        long long swaps = 0;

        selectionSortCount(arr, comparisons, swaps);

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << comparisons << endl;
        cout << swaps << endl;
    }

    return 0;
}
