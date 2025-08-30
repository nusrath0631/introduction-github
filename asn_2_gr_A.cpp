#include <iostream>
#include <ctime>
#include <cstdlib>

#define SIZE 100000

int t[SIZE];
int temp;
clock_t start_time, end_time;
double totalTime;

void heapSort(int a[]);
void mergeSort(int a[]);
void quickSort(int a[]);

using namespace std;

int main()
{
    int a[SIZE];
    int i;

    srand(time(0));
    for(i = 0; i < SIZE; i++)
        a[i] = (rand() % 10000) - 1000;

    heapSort(a);
    mergeSort(a);
    quickSort(a);

    return 0;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && arr[l] > arr[largest])
        largest = l;

    if(r < n && arr[r] > arr[largest])
        largest = r;

    if(largest != i)
    {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int a[])
{
    int i;

    cout << "Heap sort in progress. Wait ...";
    start_time = clock();

    for(i = 0; i < SIZE; i++)
        t[i] = a[i];

    for(i = SIZE / 2 - 1; i >= 0; i--)
        heapify(t, SIZE, i);

    for(i = SIZE - 1; i >= 0; i--)
    {
        temp = t[0];
        t[0] = t[i];
        t[i] = temp;

        heapify(t, i, 0);
    }

    end_time = clock();
    totalTime = (end_time - start_time) / (CLOCKS_PER_SEC * 1.0);
    cout << "\nTime required for Heap Sort: " << totalTime << " seconds.\n\n";
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = new int[n1];
    int *R = new int[n2];

    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; j = 0; k = l;
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1)
        arr[k++] = L[i++];
    while(j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSortHelper(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = l + (r - l) / 2;

        mergeSortHelper(arr, l, m);
        mergeSortHelper(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void mergeSort(int a[])
{
    int i;

    cout << "Merge sort in progress. Wait ...";
    start_time = clock();

    for(i = 0; i < SIZE; i++)
        t[i] = a[i];

    mergeSortHelper(t, 0, SIZE - 1);

    end_time = clock();
    totalTime = (end_time - start_time) / (CLOCKS_PER_SEC * 1.0);
    cout << "\nTime required for Merge Sort: " << totalTime << " seconds.\n\n";
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSortHelper(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);

        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

void quickSort(int a[])
{
    int i;

    cout << "Quick sort in progress. Wait ...";
    start_time = clock();

    for(i = 0; i < SIZE; i++)
        t[i] = a[i];

    quickSortHelper(t, 0, SIZE - 1);

    end_time = clock();
    totalTime = (end_time - start_time) / (CLOCKS_PER_SEC * 1.0);
    cout << "\nTime required for Quick Sort: " << totalTime << " seconds.\n\n";
}
