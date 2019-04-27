#include <iostream>
#include <cstdlib>
#include <ctime>
#include "AVLtree.cpp"
#include "AVLNode.h"
using namespace std;

int main(){
	ItemType items[] = {8,4,3,2};
	  AVLNode a1;
	  AVLNode a2;
	  AVLNode *aptr = new AVLNode(items[0], &a1, &a2);
	AVLTree* at1 = new AVLTree(items[1]);
	at1->PrettyDisplay();
	at1->Insert(items[0]);
	at1->PrettyDisplay();
	at1->Insert(items[2]);
	at1->PrettyDisplay();
	at1->Insert(items[1]);
	at1->Insert(items[3]);
	at1->PrettyDisplay();
}
