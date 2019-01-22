#include "QueueA.h"
#include "PQueue.h"
#include <iostream>
using namespace std;

int main()
{
	PriorityQueue a;
	QueueItemType i1 = 5;
	QueueItemType i2 = 9;
	QueueItemType i3 = 6;
	a.enqueue(i2);
	cout << a.getFront() << "\n";
	a.enqueue(i1);
	cout << a.getFront() << "\n";
	a.dequeue();
	cout << a.getFront()<< "\n";
	a.enqueue(i3);
	cout << a.getFront()<< "\n";
	a.dequeue();
	cout << a.getFront()<< "\n";
	a.dequeue();
	cout << a.getFront()<< "\n";
	return 0;
}
