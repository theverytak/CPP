// new_vector.cc
// 2016. 8. 7

#include "new_vector.h"

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
