#include "ArrayList.h"
#include<iostream>
using namespace Containers;

template<typename E, typename Cont>
ArrayList<E,Cont>::ArrayList()
{ }

template<typename E, typename Cont>
ArrayList<E,Cont>::ArrayList(Cont obj)
{
	Container = obj;
}

template<typename E, typename Cont>
Iterator<E,Cont> ArrayList<E,Cont>::iterator ()
{
	Iterator<E,Cont> p(&Container);

	return p;
}	

template<typename E, typename Cont>
bool ArrayList<E,Cont>::contains(E e)noexcept
{
	typename Cont::iterator i;

	for(i=Container.begin() ; i!=Container.end() ; i++)
		if(*i==e)
			return true;
		return false;
}	

template<typename E, typename Cont>
void ArrayList<E,Cont>::add(E e)
{
		Container.insert(Container.end(), e);
}

template<typename E, typename Cont>
void ArrayList<E,Cont>::addAll(Collection<E,Cont>& c)
{
	Cont temp;
	temp = (c.iterator()).getCont();

	typename Cont::iterator i;

	for(i=temp.begin() ; i!=temp.end() ; i++)
	{	
		Container.insert(Container.end(), *i);
	}

}	

template<typename E, typename Cont>
void ArrayList<E,Cont>::clear()noexcept
{
	Container.clear();
}


template<typename E, typename Cont>
void ArrayList<E,Cont>::remove(E e)
{
	typename Cont::iterator i;

	for(i=Container.begin() ; i!=Container.end() ; i++)
		if(*i==e)
			i = Container.erase(i);

}

template<typename E, typename Cont>
void ArrayList<E,Cont>::removeAll(Collection<E,Cont>& c)
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
void ArrayList<E,Cont>::retainAll(Collection<E,Cont>& c)
{
	clear();

	Cont temp;
	temp = (c.iterator()).getCont();

	typename Cont::iterator i;

	for(i=temp.begin() ; i!=temp.end() ; i++)
	{	
		Container.insert(Container.end(), *i);
	}

}

template<typename E, typename Cont>
int ArrayList<E,Cont>::size()noexcept
{
	return Container.size();
}

template<typename E, typename Cont>
bool ArrayList<E,Cont>::containsAll(Collection<E,Cont>& c)noexcept
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
bool ArrayList<E,Cont>::isEmpty()noexcept
{
	return (Container.size()==0);
}	

