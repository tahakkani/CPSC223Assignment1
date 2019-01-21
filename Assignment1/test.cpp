#include "QueueA.h"
#include <iostream>
using namespace std;

int main()
{
	Queue a;
	QueueItemType i1 = 5;
	QueueItemType i2 = 9;
	cout << a.isEmpty();
	a.enqueue(i1);
	cout << a.getFront();
  cout << a.isEmpty();

	a.enqueue(i2);
	cout << a.getFront();
	a.dequeue();
	cout << a.getFront();
	a.dequeue();
}
