#include "Sort.h"
#include "SortType.h"
#include "Test.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    srand(time(NULL));

    const int testNumber = 100;

    long long size[]       = {10000, 50000, 100000, 500000, 1000000};
    float initPercentage[] = {0, 25, 50, 75, 95, 99, 99.7};

    SortType sortType = _mergesort;
    for(unsigned i = 0; i < sizeof(size) / sizeof(size[0]); i++)
        for(unsigned j = 0; j < sizeof(initPercentage) / sizeof(initPercentage[0]); j++)
            for(int k = 0; k < testNumber; k++)
            {
                int initialSize = size[i] * initPercentage[j] / 100;
                test::run(size[i], initialSize, sortType);
            }

    sortType = _quicksort;
    for(unsigned i = 0; i < sizeof(size) / sizeof(size[0]); i++)
        for(unsigned j = 0; j < sizeof(initPercentage) / sizeof(initPercentage[0]); j++)
            for(int k = 0; k < testNumber; k++)
            {
                int initialSize = size[i] * initPercentage[j] / 100;
                test::run(size[i], initialSize, sortType);
            }

    sortType = _introsort;
    for(unsigned i = 0; i < sizeof(size) / sizeof(size[0]); i++)
        for(unsigned j = 0; j < sizeof(initPercentage) / sizeof(initPercentage[0]); j++)
            for(int k = 0; k < testNumber; k++)
            {
                int initialSize = size[i] * initPercentage[j] / 100;
                test::run(size[i], initialSize, sortType);
            }
}
