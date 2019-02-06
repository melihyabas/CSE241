#include<vector>
#include<iterator>

using namespace std;

#ifndef Iterator_h
#define Iterator_h
class Empty
{};
template<typename E, typename Cont = vector<E> >
class Iterator
{
public:
	Iterator();
	Iterator(Cont* obj);
	bool hasNext()noexcept;
	E next();
	void remove() throw(Empty);

	typename Cont::iterator getItr(){return itr;}
	Cont getCont(){return *Container;}
private:
	typename Cont::iterator itr;
	Cont* Container;

};

#endif