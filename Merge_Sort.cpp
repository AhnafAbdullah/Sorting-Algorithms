#include <iostream>
#include <vector>
#include <chrono>   
using namespace std;

void merge(vector<int>& array, int low, int mid, int high) {
    vector<int> arr1(array.begin() + low, array.begin() + mid + 1);
    vector<int> arr2(array.begin() + mid + 1, array.begin() + high + 1);

    int i = 0, j = 0, k = low;
    while (i < (int)arr1.size() && j < (int)arr2.size()) {
        if (arr1[i] <= arr2[j]) {
            array[k++] = arr1[i++];
        }
        else {
            array[k++] = arr2[j++];
        }
    }

    while (i < (int)arr1.size()) array[k++] = arr1[i++];
    while (j < (int)arr2.size()) array[k++] = arr2[j++];
}

void mergeSort(vector<int>& array, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    mergeSort(array, low, mid);
    mergeSort(array, mid + 1, high);
    merge(array, low, mid, high);
}

int main() {
    vector<int> arr = { 5, 3, 8, 3, 9, 1, 5, 2 };

    auto start = chrono::high_resolution_clock::now();

    mergeSort(arr, 0, (int)arr.size() - 1);

    auto stop = chrono::high_resolution_clock::now();

    // calculate duration in microseconds
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	
    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << "\n";

    cout << "Time taken by mergeSort: " << duration.count() << " microseconds\n";

    return 0;
}
