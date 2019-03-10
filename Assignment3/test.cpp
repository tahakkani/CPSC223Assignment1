#include "ListNode.h"
#include "ListP.h"
#include <iostream>
using namespace std;

int main(){
//testing listNode.h
	ItemType i[] = {2, 3, 7, 43, 8, 33, 32};
	ListNode n(i[0], NULL);
	ListNode *nPtr = &n;
	/*cout << n.getItem();
	cout << n.getNext() << endl;
	ListNode n2(i2, nPtr);
	cout << n2.getItem();
	cout << n2.getNext() << endl;
	cout << &n << endl;*/
	n.setNext(new ListNode(i[3], NULL));
//testing ListP.h
	ListP l;
//testing insert and display
	for(int j = 0; j < 7; j++){
		l.insert(1, i[j]);
	  l.display();
	}

//testing sort_quicksort
	l.sort_quicksort();
	l.display();
	
	return 0;
}
