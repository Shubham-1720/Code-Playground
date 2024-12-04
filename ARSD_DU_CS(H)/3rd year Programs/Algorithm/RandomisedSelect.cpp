#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int randomizedPartition(int arr[], int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1);
    cout<<"Random pivot element Selected: "<<pivotIndex<<endl;
    swap(arr[pivotIndex], arr[high]);
    return partition(arr, low, high);
}

int randomizedSelect(int arr[], int low, int high, int i) {
    if (low == high)
        return arr[low];

    int pivotIndex = randomizedPartition(arr, low, high);
    int k = pivotIndex - low + 1;

    if (i == k)
        return arr[pivotIndex];
    else if (i < k)
        return randomizedSelect(arr, low, pivotIndex - 1, i);
    else
        return randomizedSelect(arr, pivotIndex + 1, high, i - k);
}

int main() {
    srand(time(0)); // Seed for random number generation

    int arr[] = {3,6,4,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i = 5; // Find the 5th smallest element (i starts from 1)

    int ith_smallest = randomizedSelect(arr, 0, n - 1, i);
    cout << "The " << i << "th smallest element in the array is: " << ith_smallest << endl;

    return 0;
}
