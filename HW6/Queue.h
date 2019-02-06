#include "Collection.h"
#include<string>
#ifndef queue_h
#define queue_h

using namespace std;

template<typename E, typename Cont = vector<E> >
class Queue : virtual public Collection<E,Cont>
{	
public:
	virtual E element() = 0; //Retrieves, but does not remove, the head of this queue.
	virtual void offer(E e) = 0;	// throw(string) = 0; //Inserts the specified element into this queue
	virtual E poll()  throw(Empty) = 0;
	/*Retrieves and removes the head of this queue, or throws if this
	queue is empty.*/
};

#endif
