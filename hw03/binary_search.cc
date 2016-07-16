// binary_search.cc
// 2017. 7. 16

#include "binary_search.h"
#include <algorithm>


BinarySearch::BinarySearch()
{
  mArray = NULL;
  mArrayCount = 0;
}

// make and sort;
BinarySearch::BinarySearch(int *_array, int _arrayCount)
{
  mArray = new int[_arrayCount];
  std::copy(_array, _array + _arrayCount, mArray);
  mArrayCount = _arrayCount;

  sortArray();
}

BinarySearch::~BinarySearch()
{
  delete[] mArray;
}

int* BinarySearch::array() const
{
  return mArray;
}

int BinarySearch::arrayCount() const
{
  return mArrayCount;
}

void BinarySearch::sortArray()
{
  for(int i = 0; i < arrayCount(); i++)
  {
    for(int j = 0; j < arrayCount() - 1; j++)
    {
      if(array()[j] > array()[j + 1])
      {
        int temp = array()[j + 1];
        array()[j + 1] = array()[j];
        array()[j] = temp;
      }
    }
  }
}

int BinarySearch::getIndex(int _element)
{
  int left = 0, right = arrayCount() - 1, middle;
  while(left <= right)
  {
    middle = (left + right) / 2;

    if(array()[middle] < _element)
    {
      left = middle + 1;
    }
    else if(array()[middle] > _element)
    {
      right = middle - 1;
    }
    else if(array()[middle] == _element)
    {
      return middle;
    }
  }
  return -1;
}
