#include "QueueA.cpp"
#include "PQueue.cpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	PriorityQueue pQ;
	Queue q;
	Queue *qptr = &q;
	//The following test assigns random
	//integers between 0 and 99 to both
	//queues and then proceeds to dequeue
	//and display the front of each queue
	//to see if they, in fact, were
	//queued in the right order. It also
	//tests if the queue is empty or full.
	
	srand((unsigned)time(0));
	int iter = 0; //tracks how many times the pointer changes
	do{
		//Fills the queue with integers
    		for(int i = 0; i < MAX_QUEUE; i++){
			QueueItemType item = rand() % 100;
		  	qptr->enqueue(item);
  		}
		//Checks to see if isFull function works
  		if(qptr->isFull())
  			cout << "Queue is full\n";
		//Removes integers from the queue
  		for(int i = 0; i < MAX_QUEUE; i++){
  			cout << qptr->getFront() << "  ";
 	  		qptr->dequeue();
  		}
		//checks to see if isEmpty function works
  		if(qptr->isEmpty())
  			cout << "\nQueue is empty\n";
  		iter ++; //increases iteration
  		qptr = &pQ; //changes to priority queue
	}while(iter < 2);
}
