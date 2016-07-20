// simple_int_set.cc
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
  mElements = new int[_count];
  std::copy(_elements, _elements + _count, mElements);
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
  int* left = this->elements();
  int leftCount = this->elementCount();
  int* right = _operand.elements();
  int rightCount = _operand.elementCount();
  int* temp = new int[leftCount];
  std::copy(left, left + leftCount, temp);

  delete[] this->mElements;

  // allocate new memory to left;
  this->mElements = new int[leftCount + rightCount];
  this->mElementCount = leftCount + rightCount;

  // copy the temp and right to newly made left;
  for(int i = 0; i < leftCount; i++)
  {
    mElements[i] = temp[i];
  }
  for(int i = leftCount; i < this->elementCount(); i++)
  {
    mElements[i] = _operand.elements()[i - leftCount];
  }

  this->sortElements();

  delete[] temp;

  return this;
}

// find the index of unique members, then put it;
SimpleIntSet* SimpleIntSet::differenceSet(SimpleIntSet& _operand)
{
  int* left = this->elements();
  int leftCount = this->elementCount();
  int* right = _operand.elements();
  int rightCount = _operand.elementCount();
  int* temp = new int[leftCount];
  int indices[leftCount], index = 0;
  std::copy(left, left + leftCount, temp);

  delete[] this->mElements;

  // find the members for diff set. If found, save the index to the array indices;
  for(int i = 0; i < leftCount; i++)
  {
    for(int j = 0; j < rightCount; j++)
    {
      if(temp[i] == right[j])
      {
        break;
      }
      else if(j == rightCount - 1)
      {
        indices[index] = i;
        index++;
      }
    }
  }

  // allocate new memory to left;
  this->mElements = new int[index];
  this->mElementCount = index;

  // copy the diffset members from temp to newly made left;
  for(int i = 0; i < index; i++)
  {
    mElements[i] = temp[indices[i]];
  }

  delete[] temp;

  return this;
}



SimpleIntSet* SimpleIntSet::intersectSet(SimpleIntSet& _operand)
{
  int* left = this->elements();
  int leftCount = this->elementCount();
  int* right = _operand.elements();
  int rightCount = _operand.elementCount();
  int* temp = new int[leftCount];
  int indices[leftCount], index = 0;
  std::copy(left, left + leftCount, temp);

  delete[] this->mElements;

  // find the members for intersect set. If found, save the index to the array indices. w/ diff set, almost same;
  for(int i = 0; i < leftCount; i++)
  {
    for(int j = 0; j < rightCount; j++)
    {
      if(temp[i] == right[j])
      {
        indices[index] = i;
        index++;
        break;
      }
    }
  }

  // allocate new memory to left;
  this->mElements = new int[index];
  this->mElementCount = index;

  // copy the diffset members from temp to newly made left;
  for(int i = 0; i < index; i++)
  {
    mElements[i] = temp[indices[i]];
  }

  delete[] temp;

  return this;
}

void SimpleIntSet::printSet()
{
  sortElements();
  int num = elements()[0];
  std::cout << "{ " << num << " ";
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
