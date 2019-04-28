#include <iostream>
#include <cstdlib>
#include <ctime>
#include "AVLtree.cpp"
#include "AVLNode.h"
using namespace std;

int main(){
	ItemType items[] = {2,3,5,8,10, 15, 32, 42, 13, 12, 14,11, 7, 9,6};
	  AVLNode a1;
	  AVLNode a2;
	  AVLNode *aptr = new AVLNode(items[0], &a1, &a2);
	AVLTree* at1 = new AVLTree(items[4]);
	at1->PrettyDisplay();
	at1->Insert(items[2]);
	at1->PrettyDisplay();
	at1->Insert(items[6]);
	at1->PrettyDisplay();
	at1->Insert(items[3]);
	at1->PrettyDisplay();
	at1->Insert(items[5]);
	at1->PrettyDisplay();
	at1->Insert(items[8]);
	at1->PrettyDisplay();
	at1->Insert(items[1]);
	at1->PrettyDisplay();
	at1->Insert(items[12]);
	at1->PrettyDisplay();
	at1->Insert(items[13]);
	at1->PrettyDisplay();
	at1->Insert(items[0]);
	at1->PrettyDisplay();
	at1->Insert(items[14]);
	at1->PrettyDisplay();
}
