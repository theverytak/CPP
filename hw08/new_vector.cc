// new_vector.cc
// 2016. 8. 7

#include "new_vector.h"

template <typename T>
void NewVector::add(T _value) {
  if(sizeof(_value) == sizeof(int))
    values_.push_back(Element(_value, 'i'));
  else if(sizeof(_value) == sizeof(double))
    values_.push_back(Element(_value, 'd'));
  else if(sizeof(_value) == sizeof(char))
    values_.push_back(Element(_value, 'c'));

  count_++;
}

ostream& operator << (ostream& _os, const NewVector _nv) {
  for(int i = 0; i < _nv.count(); i++) {
    if(_nv.values_[i].type() == 'i')
      _os << static_cast<int>(_nv.values_[i].val()) << " ";
    else if(_nv.values_[i].type() == 'd')
      _os << _nv.values_[i].val() << " ";
    else if(_nv.values_[i].type() == 'c')
      _os << static_cast<char>(_nv.values_[i].val()) << " ";
  }
  _os << endl;

  return _os;
}
