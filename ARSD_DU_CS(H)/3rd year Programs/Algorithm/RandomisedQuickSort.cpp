#include <iostream>
#include <random>
using namespace std;

int partition(int arr[], int lb, int ub) {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(lb, ub); 
  int random_number = dis(gen);
  int pivot = arr[random_number];
  swap(arr[lb], arr[random_number]); // Move pivot to the beginning
  int start = lb + 1, end = ub;

  while (start <= end) {
    while (start <= end && arr[start] <= pivot) {
      start++;
    }
    while (start <= end && arr[end] > pivot) {
      end--;
    }
    if (start < end) {
      swap(arr[start], arr[end]);
    }
  }
  swap(arr[lb], arr[end]); // Place pivot in its final position
  return end;
}

void quickSort(int arr[], int lb, int ub) {
  if (lb < ub) {
    int loc = partition(arr, lb, ub);
    quickSort(arr, lb, loc - 1);
    quickSort(arr, loc + 1, ub);
  }
}

int main() {
  cout << "Quick Sort Algorithm" << endl;
  int size, value;
  cout << "Enter the size of array: " << endl;
  cin >> size;
  int arr[size];
  for (int i = 0; i < size; i++) {
    cout << "Enter the " << i + 1 << " element of your array: " << endl;
    cin >> value;
    arr[i] = value;
  }
  quickSort(arr, 0, size - 1);
  for (int t = 0; t < size; t++) {
    cout << arr[t] << " ";
  }
  cout << endl;
}
