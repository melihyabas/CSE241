#include "Collection.h"
#include "List.h"
#include "Queue.h"
#include<string>
#ifndef LinkedList_h
#define LinkedList_h

using namespace std;
namespace Containers{
/*
A collection that contains no duplicate elements. There is no order for this collection. In other
words, you don’t have to keep the insertion order of the elements.
*/
template<typename E, typename Cont = vector<E> >
class LinkedList : public List<E,Cont>, Queue<E,Cont> 
{
public:
	virtual E element(); //Retrieves, but does not remove, the head of this queue.
	virtual void offer(E e);//throw(string); //Inserts the specified element into this queue
	virtual E poll() throw(Empty);	
	LinkedList();
	LinkedList(Cont obj);	
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


private:
	Cont Container;	

};

};
#endif
