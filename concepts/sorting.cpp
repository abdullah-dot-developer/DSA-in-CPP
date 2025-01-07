// The process of arranging the data in a particular manner or order is called sorting.
// We will study three algorithm of sorting of O(n^2 ) complexity of time.

#include <iostream>
#include <vector>

using namespace std;

// Bubble Sort  --> Using swap function process of loop O(n^2)

void bubbleSort(int arr[], int n)
{
    bool isSwap = false;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }
        if (!isSwap)
        {
            return;
        }
    }
}

// SELECTION SORT ==> O(n^2) time complexity
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int smallIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smallIdx])
            {
                smallIdx = j;
            }
        }
        swap(arr[i], arr[smallIdx]);
    }
}

// INSERTION SORT --> O(n^2)
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n - 1; i++)
    {
        int curr = arr[i];
        int prev = i - 1;
        while (prev >= 0 && arr[prev] > curr)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {4, 1, 5, 2, 3, 8, 6, 9, 7};
    int n = 9;

    // bubbleSort(arr, n);
    // selectionSort(arr, n);
    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}