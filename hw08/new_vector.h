// new_vector.h
// 2016. 8. 7

#ifndef _NEW_VECTOR_H_
#define _NEW_VECTOR_H_

#include <iostream>
#include <vector>

using namespace std;

class Element {
  public:
    Element(double val, char type) { val_ = val; type_ = type; }
    double val() const { return val_; }
    char type() const { return type_; }

  private:
    double val_;
    char type_;
};

class NewVector {
  public:
    NewVector(){count_ = 0;}
    template <typename T> void add(T _value);
    inline int count() const { return count_; }

    friend ostream& operator << (ostream& _os, const NewVector _nv);

  private:
    int count_;
    vector<Element> values_;
};

ostream& operator << (ostream& _os, const NewVector _nv);

#endif  // _NEW_VECTOR_H_
