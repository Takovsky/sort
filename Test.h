#ifndef TEST_H
#define TEST_H

#include "SortType.h"
#include "Sort.h"
#include <chrono>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>

namespace test
{
void saveToFile(double time, int size, double sortedPercentage, SortType sortType)
{
    std::cout << "save: " << size << " " << sortedPercentage << std::endl;
    std::string fileName = "results/";
    fileName += toString(sortType);
    fileName += std::to_string(size);
    fileName += "-";
    fileName += std::to_string(sortedPercentage);
    fileName += ".txt";
    std::fstream file;
    file.open(fileName.c_str(), std::fstream::app);
    file << time << std::endl;
    file.close();
}

template <typename T>
void setRand(T *arr, int size)
{
    for(int i = 0; i < size; i++)
        arr[i] = rand() % 999999;
}

template <typename T>
void partialSort(T *arr, int initialSortedSize, SortType sortType)
{
    switch(sortType)
    {
    case _mergesort:
    {
        ::mergesort(arr, 0, initialSortedSize - 1);
        break;
    }
    case _quicksort:
    {
        ::quicksort(arr, 0, initialSortedSize - 1);
        break;
    }
    case _introsort:
    {
        ::introsort(arr, 0, initialSortedSize - 1);
        break;
    }
    default:
        break;
    }
}

void run(int size, int initialSortedSize, SortType sortType)
{
    using namespace std::chrono;

    int *arr = new int[size];
    setRand(arr, size);

    if(initialSortedSize != 0)
        partialSort(arr, initialSortedSize, sortType);

    high_resolution_clock::time_point begin = high_resolution_clock::now();
    switch(sortType)
    {
    case _mergesort:
    {
        ::mergesort(arr, 0, size - 1);
        break;
    }
    case _quicksort:
    {
        ::quicksort(arr, 0, size - 1);
        break;
    }
    case _introsort:
    {
        ::introsort(arr, 0, size - 1);
        break;
    }
    default:
        break;
    }
    high_resolution_clock::time_point end = high_resolution_clock::now();
    //    std::clock_t end        = clock();
    duration<double, std::milli> time = end - begin;
    double sortedPercentage           = double(initialSortedSize * 100) / double(size);
    std::cout << "run: " << size << " " << initialSortedSize << " " << sortedPercentage << std::endl;

    saveToFile(time.count(), size, sortedPercentage, sortType);
    delete[] arr;
}

} // namespace test

#endif // TEST_H
