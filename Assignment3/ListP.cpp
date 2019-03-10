#include "ListP.h"
#include <iostream>

using namespace std;

ListP::ListP(){
	head = NULL;
	size = 0;
}

ListP::ListP(const ListP & l){
	if(l.head == NULL)
		head = NULL;
	else{
	  head = new ListNode(l.head->item);
	  ListNode *curr = head;
	  ListNode *lCurr= l.head;
    while(lCurr->next){
		  curr->next = new ListNode(lCurr->next->item);
		  curr = curr->next;
		  lCurr = lCurr->next;
		}
	}
}

ListP::~ListP(){
  ListNode *curr;
  while (head != NULL) {
		curr = head;
    head = head->next;
    delete curr;
  }
}

bool ListP::isEmpty() const{
  if(head == NULL)
	  return true;
  return false;
}

int ListP::getSize() const{
  return size;
}

void ListP::insert(int pos, const ItemType & x){
	if(head == NULL){
	  ListNode *newNode = new ListNode(x,NULL);
		head = newNode;
	}
	else if(pos == 1){
		head = new ListNode(x, head);
	}
	else if(pos == getSize() + 1){
		ListNode *curr = head;
		while(curr->next)
			curr = curr->next;
		curr->next = new ListNode(x,NULL);
	}
	else{
		ListNode *curr = head;

	  for (int i = 2; i < pos; i++){
		  curr = curr->next;
	  }
	  ListNode *hold = curr->next;
	  ListNode *newNode = new ListNode(x, hold);
	  curr->next = newNode;
	}
	size++;
}
// remove the item at the position "pos"
void ListP::remove(int pos){
	if(!head)
		return;
	else{
	  ListNode *curr = head;
	  ListNode *prev;
	  if(pos == 1){
			head = head->next;
			delete curr;
		}
		else{
			for(int i = 1; i < pos; i++){
			prev = curr;
			curr = curr->next;
		  }
		  prev->next = curr->next;
		  delete curr;
		}
	}
}

void ListP::display()
{
  ListNode *nodePtr;
  nodePtr = head;

  while (nodePtr){
    cout << nodePtr->item << " ";
    nodePtr = nodePtr->next;
  }
  cout << endl;
}
 // for debugging purpose, print out the list
void ListP::sort_mergesort(){
}

void ListP::sort_quicksort(){
	head = quicksort(head);
}

void ListP::partition(ListNode * &Larger, ListNode * &Smaller, ListNode * &pivot ){
	ListNode *index = NULL;
	ListNode *lastSmall = NULL;
	ListNode *lastLarge = NULL;
	index = pivot->next;
	pivot->next = NULL;
	while(index){
		if(index->item < pivot->item){
			if(Smaller == NULL){
				Smaller = index;
				lastSmall = index;
			}
			else{
				lastSmall->next = index;
				lastSmall = lastSmall->next;
			}
			index = index->next;
			lastSmall->next = NULL;
		}
		else{
			if(Larger == NULL){
				Larger = index;
				lastLarge = index;
			}
			else{
				lastLarge->next = index;
				lastLarge = lastLarge->next;
			}
			index = index->next;
			lastLarge->next = NULL;
		}
	}
}

ListNode * ListP::quicksort(ListNode *begin){
	if(begin == NULL || begin->next == NULL)
		return begin;
	ListNode *left = NULL;
	ListNode *right = NULL;
	partition (right, left, begin);
	ListNode *lefthead = quicksort(left);
	begin->next = quicksort(right);
	
	if(left == NULL)
		return begin;
	else{
		getTail(lefthead)->next = begin;
  	return lefthead;
	}
}

ListNode * ListP::getTail(ListNode *begin){
	ListNode *curr = begin;
	while(curr->next)
		curr = curr->next;
	return curr;
}
