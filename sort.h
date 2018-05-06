#ifndef SORT_H
#define SORT_H

#include "SortHelper.h"
#include <cmath>

template <typename T>
void mergesort(T *arr, int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;

        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

template <typename T>
void quicksort(T *arr, int left, int right)
{
    if(left < right)
    {
        int partitionPoint = partition(arr, left, right);
        quicksort(arr, left, partitionPoint);
        quicksort(arr, partitionPoint + 1, right);
    }
}

template <typename T>
void introsort(T *arr, int left, int right)
{
    int depthLimit = 2 * log(right - left);

    introsortUtil(arr, left, right, depthLimit);
}

template <typename T>
void revert(T *arr, int left, int right)
{
    for(int i = left, j = right; i < j; i++, j--)
        swap(arr[i], arr[j]);
}

template <typename T>
bool isSortedDownUp(T *arr, int left, int right)
{
    for(int i = left + 1; i <= right; i++)
        if(arr[i] < arr[i - 1])
            return false;
    return true;
}

template <typename T>
bool isSortedUpDown(T *arr, int left, int right)
{
    for(int i = left + 1; i <= right; i++)
        if(arr[i] > arr[i - 1])
            return false;
    return true;
}

#endif // SORT_H

// https://www.geeksforgeeks.org/merge-sort/
// https://www.geeksforgeeks.org/know-your-sorting-algorithm-set-2-introsort-cs-sorting-weapon/
// http://www.algorytm.org/algorytmy-sortowania/sortowanie-szybkie-quicksort/quick-1-c.html
// https://www.geeksforgeeks.org/know-your-sorting-algorithm-set-2-introsort-cs-sorting-weapon/
