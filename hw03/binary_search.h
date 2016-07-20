// binary_search.h
// 2017. 7. 16

#ifndef _BINARY_SEARCH_H_
#define _BINARY_SEARCH_H_

class BinarySearch
{
private:
    int *mArray;
    int mArrayCount;

    void sortArray(); // you can reuse your previous sort assignment

public:
    BinarySearch();
    BinarySearch(int *_array, int _arrayCount);
    ~BinarySearch();

    int *array() const;
    int arrayCount() const;
    int getIndex(int _element); // return -1 when element doesn't exist
};

#endif // _BINARY_SEARCH_H_
