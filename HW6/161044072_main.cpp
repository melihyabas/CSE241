#include<iostream>
#include <set>
#include <queue>
#include <list>
#include <vector>
#include "Collection.h"
#include "HashSet.h"
#include "HashSet.cpp"
#include "ArrayList.h"
#include "ArrayList.cpp"
#include "LinkedList.h"
#include "LinkedList.cpp"

#include "Iterator.h"
#include "Iterator.cpp"

using namespace std;


int main()
{		
		int i;

		vector<int> v, v2, v3, v4;

		for(i=0 ; i<10 ; i++)
			v.push_back(i);
		for(i=0 ; i<4 ; i++)
			v2.push_back(i);
		for(i=7 ; i<15 ; i++)
			v3.push_back(i);
		v4.push_back(89);

		cout<<"Vector 1:\t";
		for(i=0 ; i<v.size() ; i++)
				cout<<" "<<v[i];
			cout<<"\n";
		cout<<"Vector 2:\t";
		for(i=0 ; i<v2.size() ; i++)
				cout<<" "<<v2[i];	
			cout<<"\n";			
		cout<<"Vector 3:\t";
		for(i=0 ; i<v3.size() ; i++)
				cout<<" "<<v3[i];						
		
		cout<<"\n";
		cout<<"Vector 4:\t"<<v4[0]<<endl;
		cout<<"------------------------------------------------------";

  		cout<<"\n\n";
  		
  		cout<<"-TEST OF ITERATOR CLASS:\n";
  		Iterator<int,vector<int>> obj(&v), obj2(&v2), obj4(&v4);
  		cout<<"After remove function Vector 1:\t";
  		obj.remove();

		for(i=0 ; i<v.size() ; i++)
				cout<<" "<<v[i];  
		cout<<"\n";	
		cout<<"Return value of next function:\t";			
  		cout<<obj.next();
  			cout<<"\n";
  	
  		cout<<"Return value of hasNext function for Vector 4:\t";
  		cout<<obj4.hasNext();
				cout<<"\n";
  		cout<<"Return value of hasNext function for Vector 1:\t";
  		cout<<obj.hasNext();
				cout<<"\n";

		cout<<"------------------------------------------------------";

		cout<<"\n\n-TEST OF HASHSET CLASS:\n";
		set<int> s, s2, s3, s4;
		vector<int> sh, sh2, sh3, sh4;
		list<int> sx, sx2, sx3, sx4;

		for(i=0 ; i<10 ; i++)
			s.insert(i);
		for(i=0 ; i<4 ; i++)
			s2.insert(i);
		for(i=7 ; i<15 ; i++)
			s3.insert(i);
		for(i=0 ; i<10 ; i++)
			sh.push_back(i);
		for(i=0 ; i<4 ; i++)
			sh2.push_back(i);
		for(i=7 ; i<15 ; i++)
			sh3.push_back(i);		
		for(i=0 ; i<10 ; i++)
			sx.push_back(i);
		for(i=0 ; i<4 ; i++)
			sx2.push_back(i);
		for(i=7 ; i<15 ; i++)
			sx3.push_back(i);	

  		HashSet<int,set<int>> st(s);
  	  	HashSet<int,set<int>> st2(s2);
  	  	HashSet<int,set<int>> st3(s3);
  	  	HashSet<int,set<int>> st4(s4);


  		HashSet<int,list<int>> stx(sx);
  	  	HashSet<int,list<int>> stx2(sx2);
  	  	HashSet<int,list<int>> stx3(sx3);
  	  	HashSet<int,list<int>> stx4(sx4);

  		HashSet<int,vector<int>> sth(sh);
  	  	HashSet<int,vector<int>> sth2(sh2);
  	  	HashSet<int,vector<int>> sth3(sh3);
  	  	HashSet<int,vector<int>> sth4(sh4);
  		cout<<"contains function:\n";
  		cout<<"Set 1 contains 1:\t"<<st.contains(1)<<endl;
  	  	cout<<"Set 1 does not contain 17:\t"<<st.contains(17)<<endl;
    	cout<<"List 1 contains 1:\t"<<stx.contains(1)<<endl;
  	  	cout<<"List 1 does not contain 17:\t"<<stx.contains(17)<<endl;	  	
    	cout<<"Vector 1 contains 1:\t"<<sth.contains(1)<<endl;
  	  	cout<<"Vector 1 does not contain 17:\t"<<sth.contains(17)<<endl;

  		
  		cout<<"\ncontainsAll function:"<<endl;
		cout<<"Set 1 contains set 2:"<<st.containsAll(st2)<<endl;
		cout<<"Set 1 does not contain set 3:"<<st.containsAll(st3)<<endl;
		cout<<"List 1 contains List 2:"<<stx.containsAll(stx2)<<endl;
		cout<<"List 1 does not contain List 3:"<<stx.containsAll(stx3)<<endl;		
		cout<<"Vector 1 contains vector 2:"<<sth.containsAll(sth2)<<endl;
		cout<<"Vector 1 does not contain vector 3:"<<sth.containsAll(sth3)<<endl;		

  	  	cout<<"Set 1 contains Set 2:\t"<<st.containsAll(st2)<<endl;
	  	cout<<"Set 1 does not contain Set 3:\t"<<st.containsAll(st3)<<endl;
  	  	cout<<"List 1 contains List 2:\t"<<stx.containsAll(stx2)<<endl;
	  	cout<<"List 1 does not contain List 3:\t"<<stx.containsAll(stx3)<<endl;	  	
  	  	cout<<"Vector 1 contains vector 2:\t"<<sth.containsAll(sth2)<<endl;
	  	cout<<"Vector 1 does not contain vector 3:\t"<<sth.containsAll(sth3)<<endl;

		cout<<"\n";
	  	cout<<"isEmpty function:\n";
	  	cout<<"Set 4 is Empty:\t"<<st4.isEmpty()<<endl;
	  	cout<<"Set 3 is not Empty:\t"<<st3.isEmpty()<<endl<<endl;
	  	cout<<"List 4 is Empty:\t"<<stx4.isEmpty()<<endl;
	  	cout<<"List 3 is not Empty:\t"<<stx3.isEmpty()<<endl<<endl;
	  	cout<<"Vector 4 is Empty:\t"<<sth4.isEmpty()<<endl;
	  	cout<<"Vector 3 is not Empty:\t"<<sth3.isEmpty()<<endl<<endl;	  	
		cout<<"\n";	  
	  	cout<<"size function:\n";
	  	HashSet<int,set<int>> adding(s);
	  	HashSet<int,vector<int>> addingh(sh);//WRITE FUNCTION NAMES!!	 
	  	HashSet<int,list<int>> addingx(sx);

	  	cout<<"Size set:"<<adding.size()<<endl;	
	  	cout<<"Size vector:"<<addingh.size()<<endl;	
	  	cout<<"Size list:"<<addingx.size()<<endl;	

 		cout<<"\n";
	  	cout<<"add function:\n";
	  	adding.add(30);
	  	cout<<"And Then New Size of set:"<<adding.size()<<endl;	
	  	adding.add(39);
	  	cout<<"And Then New Size of list:"<<addingx.size()<<endl;		  	
	  	addingh.add(124);
	  	cout<<"And Then New Size of vector:"<<addingh.size()<<endl;		  	
	  	cout<<"\n";
	  	cout<<"addAll function:\n";
		st.addAll(st3);
		cout<<"Size of set after addAll function:"<<st.size()<<endl;
		stx.addAll(stx3);
		cout<<"Size of list after addAll function:"<<stx.size()<<endl;		
		sth.addAll(sth3);
		cout<<"Size of vector after addAll function:"<<sth.size()<<endl;				
		cout<<"\n";	  
	  	cout<<"remove function:\n";
		st.remove(3);
		cout<<"Size of set after remove function:"<<st.size()<<endl;
		stx.remove(3);
		cout<<"Size of list after remove function:"<<stx.size()<<endl;		
		sth.remove(3);
		cout<<"Size of vector after remove function:"<<sth.size()<<endl;				
		cout<<"\n";

	  	cout<<"retainAll function:";
		st.retainAll(st2);
		cout<<"\nSize of set after retainAll function:"<<adding.size()<<endl;	
			stx.retainAll(stx2);
		cout<<"\nSize of list after retainAll function:"<<addingx.size()<<endl;	
		sth.retainAll(sth2);
		cout<<"\nSize of vector after retainAll function:"<<addingh.size()<<endl;		
		cout<<"\n";

	  	cout<<"removeAll function:";

		adding.removeAll(st2);
		cout<<"\nSize of set after removeAll function:"<<adding.size();	

		addingx.removeAll(stx2);
		cout<<"\nSize of list after removeAll function:"<<addingx.size();			
		addingh.removeAll(sth2);
		cout<<"\nSize of vector after removeAll function:"<<addingh.size();	

	
		adding.clear();
		cout<<"\nSize of set after clear function:"<<adding.size();	
		addingx.clear();
		cout<<"\nSize of list after clear function:"<<addingx.size();			
		addingh.clear();
		cout<<"\nSize of vector after clear function:"<<addingh.size();	


		cout<<"\n------------------------------------------------------";

  		cout<<"\n\n\n";

  		cout<<"-TEST OF ARRAYLIST CLASS:"<<endl;

		vector<int> a, a2, a3, a4;
		set<int> as, as2, as3, as4;
		list<int> ax, ax2, ax3, ax4;

		for(i=0 ; i<10 ; i++)
			a.push_back(i);
		for(i=0 ; i<4 ; i++)
			a2.push_back(i);
		for(i=7 ; i<15 ; i++)
			a3.push_back(i);

		for(i=0 ; i<10 ; i++)
			ax.push_back(i);
		for(i=0 ; i<4 ; i++)
			ax2.push_back(i);
		for(i=7 ; i<15 ; i++)
			ax3.push_back(i);

		for(i=0 ; i<10 ; i++)
			as.insert (i);
		for(i=0 ; i<4 ; i++)
			as2.insert (i);
		for(i=7 ; i<15 ; i++)
			as3.insert (i);

  		ArrayList<int,vector<int>> at(a);
  	  	ArrayList<int,vector<int>> at2(a2);
  	  	ArrayList<int,vector<int>> at3(a3);
  	  	ArrayList<int,vector<int>> at4(a4);

  		ArrayList<int,list<int>> atx(ax);
  	  	ArrayList<int,list<int>> atx2(ax2);
  	  	ArrayList<int,list<int>> atx3(ax3);
  	  	ArrayList<int,list<int>> atx4(ax4);

  		ArrayList<int,set<int>> ats(as);
  	  	ArrayList<int,set<int>> ats2(as2);
  	  	ArrayList<int,set<int>> ats3(as3);
  	  	ArrayList<int,set<int>> ats4(as4);
  		cout<<"contains function:\n";
  		cout<<"Vector 1 contains 1:\t"<<at.contains(1)<<endl;
  	  	cout<<"Vector 1 does not contain 17:\t"<<at.contains(17)<<endl;
   		cout<<"List 1 contains 1:\t"<<atx.contains(1)<<endl;
  	  	cout<<"List 1 does not contain 17:\t"<<atx.contains(17)<<endl; 	  	
   		cout<<"Set 1 contains 1:\t"<<ats.contains(1)<<endl;
  	  	cout<<"Set 1 does not contain 17:\t"<<ats.contains(17)<<endl;

  		cout<<"\ncontainsAll function:"<<endl;
		cout<<"Vector 1 contains vector 2:"<<at.containsAll(at2)<<endl;
		cout<<"Vector 1 does not contain vector 3:"<<at.containsAll(at3)<<endl;
		cout<<"List 1 contains List 2:"<<atx.containsAll(atx2)<<endl;
		cout<<"List 1 does not contain List 3:"<<atx.containsAll(atx3)<<endl;
		cout<<"Set 1 contains set 2:"<<ats.containsAll(ats2)<<endl;
		cout<<"Set 1 does not contain set 3:"<<ats.containsAll(ats3)<<endl;
 	
		cout<<"\n";
	  	cout<<"isEmpty function:\n";
	  	cout<<"Vector 4 is Empty:\t"<<at4.isEmpty()<<endl;
	  	cout<<"Vector 3 is not Empty:\t"<<at3.isEmpty()<<endl<<endl;
	  	cout<<"List 4 is Empty:\t"<<atx4.isEmpty()<<endl;
	  	cout<<"List 3 is not Empty:\t"<<atx3.isEmpty()<<endl<<endl;	  	
	  	cout<<"Set 4 is Empty:\t"<<ats4.isEmpty()<<endl;
	  	cout<<"Set 3 is not Empty:\t"<<ats3.isEmpty()<<endl<<endl;	  	
		cout<<"\n";	  
	  	cout<<"size function:\n";
	  	ArrayList<int,vector<int>> addingA(a);
	  	ArrayList<int,set<int>> addingAs(as);
	  	ArrayList<int,list<int>> addingAx(ax);

	  	cout<<"Size of vector:"<<addingA.size()<<endl;	
	  	cout<<"Size of list:"<<addingAx.size()<<endl;	

	  	cout<<"Size of set:"<<addingAs.size()<<endl;	

 		cout<<"\n";
	  	cout<<"add function:\n";
	  	addingA.add(30);
	  	cout<<"And Then New Size of Vector:"<<addingA.size()<<endl;	
	    addingAx.add(30);
	  	cout<<"And Then New Size of List:"<<addingAx.size()<<endl;		
	  	addingAs.add(30);
	  	cout<<"And Then New Size of Set:"<<addingAs.size()<<endl;		  	
	  	cout<<"\n";
	  	cout<<"addAll function:\n";
		at.addAll(at3);
		cout<<"Size of vector after addAll function:"<<at.size()<<endl;
		atx.addAll(atx3);
		cout<<"Size of list after addAll function:"<<atx.size()<<endl;		
		ats.addAll(ats3);
		cout<<"Size of set after addAll function:"<<ats.size()<<endl;				
		cout<<"\n";	  
	  	cout<<"remove function:\n";
		at.remove(3);
		cout<<"Size of vector after remove function:"<<at.size()<<endl;	
		atx.remove(3);
		cout<<"Size of list after remove function:"<<atx.size()<<endl;			
		ats.remove(3);
		cout<<"Size of set after remove function:"<<ats.size()<<endl;				
		cout<<"\n";

	  	cout<<"retainAll function:";
		at.retainAll(at2);
		cout<<"\nSize of vector after retainAll function:"<<addingA.size()<<endl;	
		atx.retainAll(atx2);
		cout<<"\nSize of list after retainAll function:"<<addingAx.size()<<endl;		
		cout<<"\n";
		ats.retainAll(ats2);
		cout<<"\nSize of set after retainAll function:"<<addingAs.size()<<endl;	
		cout<<"\n";		
	  	cout<<"removeAll function:";
		addingA.removeAll(at2);
		cout<<"\nSize of vector after removeAll function:"<<addingA.size();	
		addingAx.removeAll(atx2);
		cout<<"\nSize of list after removeAll function:"<<addingAx.size();		
		addingAs.removeAll(ats2);
		cout<<"\nSize of set after removeAll function:"<<addingAs.size();		
	  	cout<<"\n\n[] Operator function:"<<endl;
	  		cout<<"Thir index of container: Container[3] is "<<addingA[3];
		

		addingA.clear();
		cout<<"\nSize of vector after clear function:"<<addingA.size()<<endl;	
		addingAx.clear();
		cout<<"\nSize of list after clear function:"<<addingAx.size()<<endl;		

		addingAs.clear();
		cout<<"\nSize of set after clear function:"<<addingAs.size()<<endl;			

		cout<<"------------------------------------------------------";

  		cout<<"\n\n\n";

  	cout<<"-TEST OF LINKEDLIST CLASS:"<<endl;

		vector<int> q, q2, q3, q4;
		set<int> qs, qs2,qs3,qs4;
		list<int> qx, qx2, qx3, qx4;		
		for(i=1 ; i<10 ; i++)
			q.push_back(i);
		for(i=1 ; i<4 ; i++)
			q2.push_back(i);
		for(i=7 ; i<15 ; i++)
			q3.push_back(i);
	
		for(i=1 ; i<10 ; i++)
			qx.push_back(i);
		for(i=1 ; i<4 ; i++)
			qx2.push_back(i);
		for(i=7 ; i<15 ; i++)
			qx3.push_back(i);	
		
		for(i=1 ; i<10 ; i++)
			qs.insert (i);
		for(i=1 ; i<4 ; i++)
			qs2.insert (i);
		for(i=7 ; i<15 ; i++)
			qs3.insert (i);

  		LinkedList<int,vector<int>> qt(q);
  	  	LinkedList<int,vector<int>> qt2(q2);
  	  	LinkedList<int,vector<int>> qt3(q3);
  	  	LinkedList<int,vector<int>> qt4(q4);

  		LinkedList<int,list<int>> qtx(qx);
  	  	LinkedList<int,list<int>> qtx2(qx2);
  	  	LinkedList<int,list<int>> qtx3(qx3);
  	  	LinkedList<int,list<int>> qtx4(qx4);

  		LinkedList<int,set<int>> qts(qs);
  	  	LinkedList<int,set<int>> qts2(qs2);
  	  	LinkedList<int,set<int>> qts3(qs3);
  	  	LinkedList<int,set<int>> qts4(qs4);
  		cout<<"contains function:\n";
  		cout<<"Vector 1 contains 1:\t"<<qt.contains(1)<<endl;
  	  	cout<<"Vector 1 does not contain 17:\t"<<qt.contains(17)<<endl;
		cout<<"List 1 contains 1:\t"<<qtx.contains(1)<<endl;
  	  	cout<<"List 1 does not contain 17:\t"<<qtx.contains(17)<<endl;    
    	cout<<"Set 1 contains 1:\t"<<qts.contains(1)<<endl;
  	  	cout<<"Set 1 does not contain 17:\t"<<qts.contains(17)<<endl;

  		cout<<"\ncontainsAll function:"<<endl;
		cout<<"Vector 1 contains vector 2:"<<qt.containsAll(qt2)<<endl;
		cout<<"Vector 1 does not contain vector 3:"<<qt.containsAll(qt3)<<endl;
		cout<<"List 1 contains List 2:"<<qtx.containsAll(qtx2)<<endl;
		cout<<"List 1 does not contain List 3:"<<qtx.containsAll(qtx3)<<endl;
		cout<<"Set 1 contains set 2:"<<qts.containsAll(qts2)<<endl;
		cout<<"Set 1 does not contain set 3:"<<qts.containsAll(qts3)<<endl;

  	  	cout<<"Vector 1 contains vector 2:\t"<<qt.containsAll(qt2)<<endl;
	  	cout<<"Vector 1 does not contain vector 3:\t"<<qt.containsAll(qt3)<<endl;
	  	cout<<"List 1 contains List 2:\t"<<qtx.containsAll(qtx2)<<endl;
	  	cout<<"List 1 does not contain List 3:\t"<<qtx.containsAll(qtx3)<<endl;	  	
		cout<<"\n";
	  	cout<<"isEmpty function:\n";
	  	cout<<"Vector 4 is Empty:\t"<<qt4.isEmpty()<<endl;
	  	cout<<"Vector 3 is not Empty:\t"<<qt3.isEmpty()<<endl<<endl;
	  	cout<<"List 4 is Empty:\t"<<qtx4.isEmpty()<<endl;
	  	cout<<"List 3 is not Empty:\t"<<qtx3.isEmpty()<<endl<<endl;	  	
	  	cout<<"Set 4 is Empty:\t"<<qts4.isEmpty()<<endl;
	  	cout<<"Set 3 is not Empty:\t"<<qts3.isEmpty()<<endl<<endl;	  	
		cout<<"\n";	  
	  	cout<<"size function:\n";
	  	LinkedList<int,vector<int>> addingQ(q); 
	  	LinkedList<int,set<int>> addingQs(qs); 
	  	LinkedList<int,list<int>> addingQx(qx); 

	  	cout<<"Size of vector:"<<addingQ.size()<<endl;	
 		cout<<"\n";

	  	cout<<"Size of list:"<<addingQx.size()<<endl;	
 		cout<<"\n"; 		
   		cout<<"Size of set:"<<addingQs.size()<<endl;	
 		cout<<"\n";		
	  	cout<<"add function:\n";
	  	addingQ.add(30);
	  	cout<<"And Then New Size of Vector:"<<addingQ.size()<<endl;	
	 	cout<<"\n";
	  	addingQx.add(30);
	  	cout<<"And Then New Size of List:"<<addingQx.size()<<endl;	
	 	cout<<"\n";
	  	addingQs.add(30);
	  	cout<<"And Then New Size of Set:"<<addingQs.size()<<endl;	
	 	cout<<"\n";

	  	cout<<"addAll function:\n";
		qt.addAll(qt3);
		cout<<"Size of vector after addAll function:"<<qt.size()<<endl;		
		cout<<"\n";	 
		qtx.addAll(qtx3);
		cout<<"Size of list after addAll function:"<<qtx.size()<<endl;		
		cout<<"\n";	 		 
		qts.addAll(qts3);
		cout<<"Size of set after addAll function:"<<qts.size()<<endl;		
		cout<<"\n";	  		
	  	cout<<"remove function:\n";
		qt.remove(3);
		cout<<"Size of vector after remove function:"<<qt.size()<<endl;		
		cout<<"\n";
		qtx.remove(3);
		cout<<"Size of list after remove function:"<<qtx.size()<<endl;		
		cout<<"\n";		
		qts.remove(3);
		cout<<"Size of set after remove function:"<<qts.size()<<endl;		
		cout<<"\n";		

	  	cout<<"retainAll function:";
		qt.retainAll(qt2);
		cout<<"\nSize of vector after retainAll function:"<<addingQ.size()<<endl;	
		cout<<"\n";
		qtx.retainAll(qtx2);
		cout<<"\nSize of list after retainAll function:"<<addingQx.size()<<endl;	
		cout<<"\n";		
		qts.retainAll(qts2);
		cout<<"\nSize of set after retainAll function:"<<addingQs.size()<<endl;	
		cout<<"\n";		
	  	cout<<"removeAll function:";
		addingQ.removeAll(at2);
		cout<<"\nSize of vector after removeAll function:"<<addingQ.size();	
		cout<<"\n";
		addingQx.removeAll(atx2);
		cout<<"\nSize of list after removeAll function:"<<addingQx.size();	
		cout<<"\n";		
		addingQs.removeAll(ats2);
		cout<<"\nSize of set after removeAll function:"<<addingQs.size();	
		cout<<"\n";		
	  	cout<<"\noffer function:\n";
	  	addingQ.offer(124);
	  	cout<<"And Then New Size of vector:"<<addingQ.size()<<endl;
		cout<<"\n";
	  	addingQx.offer(14);
	  	cout<<"And Then New Size of list:"<<addingQx.size()<<endl;
		cout<<"\n";		
	  	addingQs.offer(424);
	  	cout<<"And Then New Size of set:"<<addingQs.size()<<endl;
		cout<<"\n";		
	  	cout<<"\nelement function:\n";
	  	cout<<"Head of this vector:"<<(addingQ.element());	
		cout<<"\n";
	  	cout<<"Head of this list:"<<(addingQx.element());	
		cout<<"\n";		
	  	cout<<"Head of this set:"<<(addingQs.element());	
		cout<<"\n";		
	  	cout<<"\npoll function:\n";
	  	try
	  	{
	  		cout<<"Head of this vector:"<<(addingQ.poll());	
	  	}
	  	catch(Empty)
	  	{
	  		cout<<"Error! This container is empty."<<endl;
	  		exit(0);
	  	}	
	  	try
	  	{
	  		cout<<"Head of this vector:"<<(addingQx.poll());	
	  	}
	  	catch(Empty)
	  	{
	  		cout<<"Error! This container is empty."<<endl;
	  		exit(0);
	  	}		  	
	  	try
	  	{
	  		cout<<"\nHead of this set:"<<(addingQs.poll());	
	  	}
	  	catch(Empty)
	  	{
	  		cout<<"Error! This container is empty."<<endl;
	  		exit(0);
	  	}	  	  	  	
		addingQ.clear();
		cout<<"\nSize of vector after clear function:"<<addingQ.size()<<endl;	
		addingQx.clear();
		cout<<"\nSize of vector after clear function:"<<addingQx.size()<<endl;		
		addingQs.clear();
		cout<<"\nSize of set after clear function:"<<addingQs.size()<<endl;	
		cout<<"------------------------------------------------------";

  		cout<<"\n\n\n";

	return 0;
}