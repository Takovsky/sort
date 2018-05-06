#ifndef SORTHELPER_H
#define SORTHELPER_H
#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a     = b;
    b     = tmp;
}

template <typename T>
void merge(T *arr, int left, int mid, int right)
{

    int leftSize  = mid - left + 1;
    int rightSize = right - mid;
    int *leftArr  = new int[leftSize];
    int *rightArr = new int[rightSize];

    for(int i = 0; i < leftSize; i++)
        leftArr[i] = arr[left + i];
    for(int j = 0; j < rightSize; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;
    while(i < leftSize and j < rightSize)
    {
        if(leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while(i < leftSize)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while(j < rightSize)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    delete[] leftArr;
    delete[] rightArr;
}

template <typename T>
int partition(T *arr, int left, int right)
{
    int pivot = arr[(right + left) / 2];

    int i = left;
    int j = right;
    while(true)
    {
        for(; arr[j] > pivot; j--)
            ;
        for(; arr[i] < pivot; i++)
            ;
        if(i < j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        else
            return j;
    }
}

template <typename T>
void insertionsort(T *arr, int left, int right)
{
    for(int i = left + 1, j; i <= right; i++)
    {
        T tmp = arr[i];
        for(j = i; j > left and tmp < arr[j - 1]; j--)
            arr[j] = arr[j - 1];
        arr[j] = tmp;
    }
}

template <typename T>
void moveDown(T *arr, int i, int size)
{
    int j;
    while(i <= size / 2)
    {
        j = 2 * i;
        if(j + 1 <= size and arr[j + 1] > arr[j])
            j = j + 1;
        if(arr[i] < arr[j])
            swap(arr[i], arr[j]);
        else
            break;
        i = j;
    }
}

template <typename T>
void heapsort(T *arr, int left, int right)
{
    for(int i = (right + left) / 2 - 1; i >= left; i--)
        moveDown(arr, i, right - left);
    for(int i = right; i >= left + 1; i--)
    {
        swap(arr[0], arr[i]);
        moveDown(arr, 0, i - 1);
    }
}

template <typename T>
int medianOfThree(T *arr, int left, int right)
{
    if(arr[left] < arr[(left + right) / 2] and arr[(left + right) / 2] < arr[right])
        return (left + right) / 2;

    if(arr[left] < arr[right] and arr[right] <= arr[(left + right) / 2])
        return right;

    if(arr[(left + right) / 2] <= arr[left] and arr[left] < arr[right])
        return left;

    if(arr[(left + right) / 2] < arr[right] and arr[right] <= arr[left])
        return right;

    if(arr[right] <= arr[left] and arr[left] < arr[(left + right) / 2])
        return left;

    if(arr[right] <= arr[(left + right) / 2] and arr[(left + right) / 2] <= arr[right])
        return (left + right) / 2;
}

template <typename T>
void introsortUtil(T *arr, int left, int right, int depthLimit)
{
    int size = right - left;

    if(size < 16)
    {
        insertionsort(arr, left, right);
        return;
    }

    //    if(depthLimit == 0)
    //    {
    heapsort(arr, left, right);
    return;
    //    }

    int pivot = medianOfThree(arr, left, right);

    // Swap the values pointed by the two pointers
    swap(arr[pivot], arr[right]);

    // Perform Quick Sort
    int partitionPoint = partition(arr, left, right);
    introsortUtil(arr, left, partitionPoint - 1, depthLimit - 1);
    introsortUtil(arr, partitionPoint + 1, right, depthLimit - 1);
}

#endif // SORTHELPER_H
