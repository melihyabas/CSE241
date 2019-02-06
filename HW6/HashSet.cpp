#include "HashSet.h"
#include<iostream>

using namespace Containers;

template<typename E, typename Cont>
HashSet<E,Cont>::HashSet()
{ }

template<typename E, typename Cont>
HashSet<E,Cont>::HashSet(Cont obj)
{
	Container = obj;
}

template<typename E, typename Cont>
Iterator<E,Cont> HashSet<E,Cont>::iterator ()
{
	Iterator<E,Cont> p(&Container);

	return p;
}	

template<typename E, typename Cont>
bool HashSet<E,Cont>::contains(E e)noexcept
{
	typename Cont::iterator i;

	for(i=Container.begin() ; i!=Container.end() ; i++)
		if(*i==e)
			return true;
		return false;
}	

template<typename E, typename Cont>
void HashSet<E,Cont>::add(E e)
{
	if(!(contains(e)))
	{	
		Container.insert(Container.end(), e);
	}
}

template<typename E, typename Cont>
void HashSet<E,Cont>::addAll(Collection<E,Cont>& c)
{
	Cont temp;
	temp = (c.iterator()).getCont();

	typename Cont::iterator i;

	for(i=temp.begin() ; i!=temp.end() ; i++)
	{	
		if(!(contains(*i)))
		Container.insert(Container.end(), *i);
	}

}	

template<typename E, typename Cont>
void HashSet<E,Cont>::clear()noexcept
{
	Container.clear();
}


template<typename E, typename Cont>
void HashSet<E,Cont>::remove(E e)
{
	typename Cont::iterator i;

	for(i=Container.begin() ; i!=Container.end() ; i++)
		if(*i==e)
			i = Container.erase(i);

}

template<typename E, typename Cont>
void HashSet<E,Cont>::removeAll(Collection<E,Cont>& c)
{
	
	typename Cont::iterator i, j;
	Cont temp;
	temp = (c.iterator()).getCont();

	for(i=Container.begin() ; i!=Container.end() ; i++)
	{
		for(j=temp.begin() ; j!=temp.end() ; j++)
		{
			if(*i==*j)
				i = Container.erase(i);
		}

	}

}

template<typename E, typename Cont>
void HashSet<E,Cont>::retainAll(Collection<E,Cont>& c)
{
	clear();

	Cont temp;
	temp = (c.iterator()).getCont();

	typename Cont::iterator i;

	for(i=temp.begin() ; i!=temp.end() ; i++)
	{	
		if(!(contains(*i)))
		Container.insert(Container.end(), *i);
	}

}

template<typename E, typename Cont>
int HashSet<E,Cont>::size()noexcept
{
	return Container.size();
}

template<typename E, typename Cont>
bool HashSet<E,Cont>::containsAll(Collection<E,Cont>& c)noexcept
{
	int sizeC = c.size();
	int count = 0;
	typename Cont::iterator i,j;
	Cont temp;
	temp = (c.iterator()).getCont();

	for(i=Container.begin() ; i!=Container.end() ; i++)
	{
		for(j=temp.begin() ; j!=temp.end() ; j++)
		{
			if(*i==*j)
				count++;
		}
	}
		return (count==sizeC);
	return true;
}

template<typename E, typename Cont>
bool HashSet<E,Cont>::isEmpty()noexcept
{
	return (Container.size()==0);
}	

