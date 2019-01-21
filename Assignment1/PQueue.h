/** @file PQueue.h */

#include "QueueA.h"

#ifndef PRIORITYQUEUEA_H
#define PRIORITYQUEUEA_H


/** @class Queue
 * ADT queue - Array-based implementation. */
class PriorityQueue: public Queue
{
public:

   /** Default constructor. */
   PriorityQueue();

   void enqueue(QueueItemType& newItem);


}; // end Queue
#endif
// End of header file.
