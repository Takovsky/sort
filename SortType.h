#ifndef SORTTYPE_H
#define SORTTYPE_H

#include <string>

enum SortType
{
    _mergesort,
    _quicksort,
    _introsort
};

std::string toString(SortType sortType)
{
    switch(sortType)
    {
    case _mergesort:
    {
        return "mergesort";
    }
    case _quicksort:
    {
        return "quicksort";
    }
    case _introsort:
    {
        return "introsort";
    }
    default:
        return NULL;
    }
}

#endif // SORTTYPE_H
