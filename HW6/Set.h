#include "Collection.h"

#ifndef set_h
#define set_h

using namespace std;

template<typename E, typename Cont = vector<E> >
class Set : public Collection<E,Cont>
{

};

#endif
