// simple_int_set.h
// 2017. 7. 15
#include "simple_int_set.h"
#include <algorithm>
#include <iostream>


SimpleIntSet::SimpleIntSet()
{
  mElements = NULL;
  mElementCount = 0;
}

SimpleIntSet::SimpleIntSet(int *_elements, int _count)
{
  mElements = _elements;
  mElementCount = _count;
}

SimpleIntSet::~SimpleIntSet()
{
  delete[] mElements;
}

void SimpleIntSet::sortElements()
{
  for(int i = 0; i < elementCount(); i++)
  {
    for(int j = 0; j < elementCount() - 1; j++)
    {
      if(elements()[j] > elements()[j + 1])
      {
        int temp = elements()[j + 1];
        elements()[j + 1] = elements()[j];
        elements()[j] = temp;
      }
    }
  }
}

int* SimpleIntSet::elements() const
{
  return mElements;
}

int SimpleIntSet::elementCount() const
{
  return mElementCount;
}

// just put together, and sort;
SimpleIntSet* SimpleIntSet::unionSet(SimpleIntSet& _operand)
{
  this->printSet();
  _operand.printSet();
  int* left = this->elements();
  int leftCount = this->elementCount();
  int* right = _operand.elements();
  int rightCount = _operand.elementCount();
  int* temp = new int[leftCount];
  std::copy(left, left + leftCount, temp);

  delete[] this->mElements;

  this->mElements = new int[leftCount + rightCount];
  std::copy(temp, temp + leftCount, this->mElements);
  std::copy(right, right + rightCount, this->mElements + leftCount);

  this->sortElements();

  delete[] temp;

  return this;
}
SimpleIntSet* SimpleIntSet::differenceSet(SimpleIntSet& _operand)
{
  return this;
}
SimpleIntSet* SimpleIntSet::intersectSet(SimpleIntSet& _operand)
{
  return this;
}

void SimpleIntSet::printSet()
{
  sortElements();
  int num = elements()[0];
  for(int i = 1; i < elementCount(); i++)
  {
    if(mElements[i] != num)
    {
      std::cout << mElements[i] << " ";
      num = mElements[i];
    }
  }
  std::cout << "}" << std::endl;
}
