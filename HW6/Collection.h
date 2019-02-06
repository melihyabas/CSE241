#include<vector>
#include "Iterator.h"
using namespace std;
#ifndef Collection_h
#define Collection_h

template<typename E, typename Cont = vector<E> >

class Collection
{
public:
	virtual Iterator<E,Cont> iterator () = 0;
	virtual bool contains(E e)noexcept = 0;
	virtual bool containsAll(Collection<E,Cont>& c)noexcept = 0;
	virtual bool isEmpty()noexcept = 0;
	virtual void add(E e) = 0;
	virtual void addAll(Collection<E,Cont>& c) = 0;
	virtual void clear()noexcept = 0;
	virtual void remove(E e) = 0;
	virtual void removeAll(Collection<E,Cont>& c) = 0;
	virtual void retainAll(Collection<E,Cont>& c) = 0;
	virtual int size()noexcept	 = 0;
};

#endif
