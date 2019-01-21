/** @file QueueA.cpp
 * Circular array-based implementation.
 * The array has indexes to the front and back of the
 * queue. A counter tracks the number of items currently
 * in the queue. */

#include "QueueA.h"  // header file
#include <iostream>
using namespace std;

Queue::Queue() : front(0), back(MAX_QUEUE-1), count(0)
{
}  // end default constructor

bool Queue::isEmpty()
{
  if(count == 0)
    return true;
  return false;
}  // end isEmpty

bool Queue::isFull()
{
	if(count < MAX_QUEUE)
		return false;
	return true;
}

void Queue::enqueue(QueueItemType& newItem)
{
  if(isFull())
		cout << "Queue is full";
	else{
		back = (back + 1) % MAX_QUEUE;
		items[back] = newItem;
		count++;
	}

}  // end enqueue

void Queue::dequeue()
{
	if(isEmpty())
		cout << "Queue is empty";
	else{
		front = (front + 1) % MAX_QUEUE;
	}
}  // end dequeue

QueueItemType Queue::getFront()
{
	return items[front];
}  // end getFront
// End of implementation file.

