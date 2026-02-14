#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

long long comparisons = 0;
long long swaps = 0;

int partitionDirect(vector<int> &arr, int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1);
    int pivot = arr[pivotIndex];

    int i = low;
    int j = high;

    while (i <= j) {

        while (i <= high && arr[i] < pivot) {
            comparisons++;
            i++;
        }
        comparisons++;

        while (j >= low && arr[j] > pivot) {
            comparisons++;
            j--;
        }
        comparisons++;

        if (i <= j) {
            swap(arr[i], arr[j]);
            swaps++;
            i++;
            j--;
        }
    }
    return i;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int index = partitionDirect(arr, low, high);
        quickSort(arr, low, index - 1);
        quickSort(arr, index, high);
    }
}

int main() {
    srand(time(0));

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        comparisons = 0;
        swaps = 0;

        quickSort(arr, 0, n - 1);

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << comparisons << endl;
        cout << swaps << endl;
    }

    return 0;
}
