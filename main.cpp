#include <iostream>
using namespace std;

void heapify(int * arr, int n, int i) {
    int max = i; // Set the highest value to the root.
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If the value of the left child is greater than the highest value, set the highest value to the left child.
    if (left < n && arr[left] > arr[max]) {
        max = left;
    }

    // If the value of the right child is greater than the highest value, set the highest value to the right child.
    if (right < n && arr[right]> arr[max]) {
        max = right;
    }

    // If the highest value's index is not the root, swap them then recursively heapify with the new highest value as root.
    if (max != i) {
        swap(arr[i], arr[max]);
        heapify(arr, n, max);
    }
}

void printArray(int * arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

void heapSort(int * arr, int n) {

    // This for loop heapifies the input array.
    for (int i = n - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    cout << "Heapified input: { ";
    printArray(arr, n);
    cout << "}" << endl << endl << "Iterative heap sort:\n\n";

    // This for loop sorts the heap that was just heapified by the previous for loop.
    for (int i = n - 1; i >= 0; i--) {
        cout << "i=" << i << " { ";
        printArray(arr, n);
        cout << "}" << endl << endl ;

        // Set the value of the new highest value at index 0 to the end where it will no longer be accessed.
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


int main() {

    // Input the values of the array.
    int arr[] = {30,20,10,40,8,4,9,18,16,38,32,39};
    // Set n to the number of values in the array.
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Input: { ";
    printArray(arr, n);
    cout << "}" << endl << endl;

    heapSort(arr, n);
    return 0;
}