#include <iostream>
#include <cstdlib>
#include <ctime>
#include "binarysearchtree.cpp"
#include "binarytree.cpp"
#include "node.h"
using namespace std;

int main(){
	ItemType items[10] = {50,45,65,23,54,43,32,68,79,47};
		

	Node *nptr = new Node(); //constructor works!
	Node *lvl4[] = {new Node(items[3],NULL, NULL),new Node(items[3],NULL, NULL),new Node(items[3],NULL, NULL),
						new Node(items[3],NULL, NULL),new Node(items[3],NULL, NULL),new Node(items[3],NULL, NULL),
						new Node(items[3],NULL, NULL),new Node(items[3],NULL, NULL),new Node(items[3],NULL, NULL)};
	Node *lvl3[] = {new Node(items[2],lvl4[1], lvl4[1]),
						new Node(items[2],lvl4[2], lvl4[2]),new Node(items[2], lvl4[4], lvl4[5]),new Node(items[2], lvl4[6], lvl4[7])};
	Node *lvl2[] = {new Node(items[1],lvl3[0], lvl3[1]),new Node(items[1],lvl3[2], lvl3[3])};
	Node *lvl1 = new Node(items[0],lvl2[0], lvl2[1]);
	BinaryTree *btptr = new BinaryTree(items[4]);

	cout << btptr->isEmpty();
	btptr->PrettyDisplay();
	
	BinaryTree bt = *btptr;
	bt.PrettyDisplay();

	BinaryTree bt2;
	bt2.PrettyDisplay();

	bt2.inorderTraverse();
	bt2.preorderTraverse();
	bt2.postorderTraverse();
	
   	BinarySearchTree* bstptr = new BinarySearchTree();
	for(int i = 0; i < 10; i++)
		bstptr->Insert(items[i]);
		
	bstptr->PrettyDisplay();
	bstptr->remove(items[1]);
	bstptr->PrettyDisplay();
	
	cout << bstptr->FindMin();
	cout << bstptr->FindMax();
}

