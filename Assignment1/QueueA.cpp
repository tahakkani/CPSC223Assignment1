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
  if(count < 1)
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
		count --;
	}
}  // end dequeue

QueueItemType Queue::getFront()
{
	if(!isEmpty())
		return items[front];
	else
	  cout << "Queue is empty";
}  // end getFront
// End of implementation file.

