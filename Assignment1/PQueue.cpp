/* Circular array-based implementation.
 * The array has indexes to the front and back of the
 * queue. A counter tracks the number of items currently
 * in the queue.
 *
 * @author Yanping Zhang
 * @version Homework 1
 * @file PQueue.cpp
 */


#include "PQueue.h"  // header file
#include<iostream>
using namespace std;

PriorityQueue::PriorityQueue()
{
}  // end default constructor


void PriorityQueue::enqueue(QueueItemType& newItem)
{
	if(isFull())
		cout << "Queue is full";
		
	int compareIndex = back;
	while (newItem > items[compareIndex]){
		items[(compareIndex + 1) % MAX_QUEUE] = items[compareIndex];
		compareIndex--;
	}
	items[compareIndex + 1] = newItem;
	count++;
}  // end enqueue


// End of implementation file.
