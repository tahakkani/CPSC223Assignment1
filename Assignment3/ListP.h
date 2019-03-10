#include <iostream>
#include "ListNode.h"


#ifndef _LISTP
#define _LISTP
using namespace std;

class ListP
{
public:

   ListP();
   ListP(const ListP & l); // copy constructor
   ~ListP();
   
   bool isEmpty() const;
   int getSize() const;

   void insert(int pos, const ItemType & x); // insert the new item x into the position "pos"
   void remove(int pos);// remove the item at the position "pos"
   void display(); // for debugging purpose, print out the list
   void sort_mergesort();
   void sort_quicksort();

//private:
     int size; // how many items in the list
	ListNode * head;
     void partition(ListNode * &Larger, ListNode * &Smaller, ListNode * &pivot );
     ListNode * quicksort(ListNode *begin);
     ListNode * getTail(ListNode *begin);

};

#endif
