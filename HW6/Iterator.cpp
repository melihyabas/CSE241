#include "Iterator.h"

template<typename E, typename Cont>
Iterator<E,Cont>::Iterator()
{ }

template<typename E, typename Cont>
Iterator<E,Cont>::Iterator(Cont* obj)
{
	Container = obj;
	itr = obj->begin();

}

template<typename E, typename Cont>
bool Iterator<E,Cont>::hasNext()noexcept
{	
	typename Cont::iterator p;
	p = itr;
	p++;


	if(Container->end() == p)
		return false;
	else
		return true;
}

template<typename E, typename Cont>
E Iterator<E,Cont>::next()
{
	itr++;
	return *(itr);

}

template<typename E, typename Cont>
void Iterator<E,Cont>::remove() throw(Empty)
{	
	if(Container->size()==0)
		throw Empty();

	itr = Container->erase(itr);
}
