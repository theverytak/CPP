// simple_int_set.h
// 2017. 7. 15

#ifndef _SIMPLE_INT_SET_
#define _SIMPLE_INT_SET_

#define MAX_SIZE 1024

class SimpleIntSet
{
private:
    int *mElements;
    int mElementCount;

    void sortElements(); // you can reuse your previous sort assignment
    SimpleIntSet();

public:
    SimpleIntSet(int *_elements, int _count);
    ~SimpleIntSet();

    int *elements() const; // return sorted array
    int elementCount() const;

    SimpleIntSet *unionSet(SimpleIntSet& _operand);
    SimpleIntSet *differenceSet(SimpleIntSet& _operand);
    SimpleIntSet *intersectSet(SimpleIntSet& _operand);

    void printSet();
};

#endif  // _SIMPLE_INT_SET_
