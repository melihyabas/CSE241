#include "Collection.h"
#include "List.h"
#ifndef ArrayList_h
#define ArrayList_h

using namespace std;

namespace Containers{
/*
A collection that contains no duplicate elements. There is no order for this collection. In other
words, you don’t have to keep the insertion order of the elements.
*/
template<typename E, typename Cont = vector<E> >
class ArrayList : public List<E,Cont>
{
public:
	ArrayList();
	ArrayList(Cont obj);	
	virtual Iterator<E,Cont> iterator ();
	virtual bool contains(E e)noexcept;
	virtual bool containsAll(Collection<E,Cont>& c)noexcept;	
	virtual bool isEmpty()noexcept;		
	virtual void add(E e);
	virtual void addAll(Collection<E,Cont>& c);	
	virtual void clear()noexcept;
	virtual void remove(E e);
	virtual void removeAll(Collection<E,Cont>& c);
	virtual void retainAll(Collection<E,Cont>& c);
	virtual int size()noexcept;
	E operator[] (E index)
	{	
		typename Cont::iterator i = Container.begin();
		int c;
		for(c=0 ; c<=index ; c++)
			i++;

			return *(i);
	}
	/*const E& operator[] (E index)const
	{
		typename Cont::iterator i;
		int a;
		i=Container.begin();
		for(a=0 ; a<=index ; a++)
			i++;

			return *i;	
	}
	*/
private:
	Cont Container;	

};

};
#endif