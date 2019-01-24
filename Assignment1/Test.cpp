#include "QueueA.h"
//#include "PQueue.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	//PriorityQueue pQ;
	Queue q;
	//The following test assigns random
	//integers between 0 and 99 to both
	//queues and then proceeds to dequeue
	//and display the front of each queue
	//to see if they, in fact, were
	//queued in the right order
	
	srand((unsigned)time(0));
	for(int i = 0; i < MAX_QUEUE; i++){
		QueueItemType item = rand() % 50;
	//	pQ.enqueue(item);
		q.enqueue(item);
	}
	for(int i = 0; i < MAX_QUEUE; i++){
		//cout << pQ.getFront() << "\t";
		cout << q.getFront() << "\n";
	//  pQ.dequeue();
	  q.dequeue();
	}
	
}
