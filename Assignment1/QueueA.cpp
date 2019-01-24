/**
* @author Taha Hakkani
* @credit Yanping Zhang (for template)
* @version Assignment 1
* @date January 22 2019
* @file QueueA.h

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
} // end isFull

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
		cout << "Queue is empty\n";
	else{
		front = (front + 1) % MAX_QUEUE;
		count --;
	}
}  // end dequeue

//retreives the item at the front of the queue (in conjuction with returnFront(), handles exception in the case that the queue is empty
QueueItemType Queue::getFront()
{
	try{
		returnFront();
	}
	catch (string a){
		cout << a;
	}
	  
} // end getFront

// handles the exception, throws an error message if the queue is empty
QueueItemType Queue::returnFront()
{
	if(isEmpty()){
		string exceptString = "ERROR: The queue is empty\n";
		throw exceptString;
	}
	  return items[front];
}
// End of implementation file.

