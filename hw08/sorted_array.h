// sorted_array.h
// 2016. 8. 4

#ifndef _SORTED_ARRAY_H_
#define _SORTED_ARRAY_H_

#include <string>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

template <typename T>
class SortedArray {
 public:
  SortedArray() {
    values_ = NULL;
  }
  SortedArray(const SortedArray& a) {
    size_ = a.size_;
    alloc_ = a.alloc_;

    values_ = new T[size_];
    for(int i = 0; i < size_; i++)
      values_[i] = a.values_[i];
  }
  SortedArray(size_t size) {
    size_ = size;
    alloc_ = size;

    values_ = new T[size];
  }
  ~SortedArray() {
    delete[] values_;
  }

  SortedArray& operator=(const SortedArray& a) {
    size_ = a.size_;
    alloc_ = a.alloc_;

    delete[] values_;

    values_ = new T[size_];
    for(int i = 0; i < size_; i++)
      values_[i] = a.values_[i];

    return *this;
  }

  size_t size() const { return size_; }
  const T& operator()(int idx) const { return values_[idx]; }

  void Reserve(int size) {  // allocate given memory(size) beforehand;
    alloc_ = size;
    values_ = new T[alloc_];
  }
  void Add(const T& value) {
    values_[size()] = value;
    size_++;
  }

  // use Binary Search. return index of value, or -1;
  int Find(const T& value) {
    int left = 0, right = size() - 1, middle;
    while(left <= right)
    {
      middle = (left + right) / 2;

      if(values_[middle] < value)
      {
        left = middle + 1;
      }
      else if(values_[middle] > value)
      {
        right = middle - 1;
      }
      else if(values_[middle] == value)
      {
        return middle;
      }
    }
    return -1;
  }

 private:
  T* values_;
  int size_, alloc_;
};

template <typename T>
inline istream& operator>>(istream& is, SortedArray<T>& a) {
  int size;
  is >> size;
  a.Reserve(size);
  T* tempArray = new T[size];
  for(int i = 0; i < size; i++)
    is >> tempArray[i];

  sort(tempArray, tempArray + size);

  for(int i = 0; i < size; i++)
    a.Add(tempArray[i]);

  delete[] tempArray;

  return is;
}

template <typename T>
inline ostream& operator<<(ostream& os, const SortedArray<T>& a) {
  for(int i = 0; i < a.size(); i++)
    os << a(i) << " ";

  return os;
}

#endif  // _SORTED_ARRAY_H_
