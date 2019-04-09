#include <iostream>
#include "binarytree.cpp"
#include "node.h"
using namespace std;

int main(){
	ItemType items[4] = {1,2,3,4};
	BinaryTree* tptr;
	Node *nptr = new Node(); //constructor works!
	Node *lvl4[] = {new Node(items[3],NULL, NULL),new Node(items[3],NULL, NULL),new Node(items[3],NULL, NULL),
						new Node(items[3],NULL, NULL),new Node(items[3],NULL, NULL),new Node(items[3],NULL, NULL),
						new Node(items[3],NULL, NULL),new Node(items[3],NULL, NULL),new Node(items[3],NULL, NULL)};
	Node *lvl3[] = {new Node(items[2],lvl4[1], lvl4[1]),
						new Node(items[2],lvl4[2], lvl4[2]),new Node(items[2], lvl4[4], lvl4[5]),new Node(items[2], lvl4[6], lvl4[7])};
	Node *lvl2[] = {new Node(items[1],lvl3[0], lvl3[1]),new Node(items[1],lvl3[2], lvl3[3])};
	Node *lvl1 = new Node(items[0],lvl2[0], lvl2[1]);
	tptr = new BinaryTree();
	tptr->mroot = lvl1;
	//cout << tptr->isEmpty();
	//tptr->PrettyDisplay();
	BinaryTree bt = *tptr;
	//bt.PrettyDisplay();
	BinaryTree bt2;
	bt2.PrettyDisplay();
	bt2 = BinaryTree(bt);
	bt2.PrettyDisplay();
	//bt2.destroyTree(bt2.mroot);
	bt2.inorderTraverse();
	bt2.preorderTraverse();
	bt2.postorderTraverse();
}

