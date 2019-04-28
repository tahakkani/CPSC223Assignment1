// ADT AVL Tree Node:
// Spec and implementation file
//    data object: a node for a dynamic AVL tree
//    operations: two constructors
// Friend classes: AVLTree
// Contract: the items for the node are defined in class ItemType
//           and ItemType has a GOOD copy constructor

//#include "itemtype.h"
#include <cstddef>

#ifndef AVLNODE_H
#define AVLNODE_H
typedef int ItemType;
class AVLNode
{
public:
	
   // creates a node with a given item and kids
   // post: the item of the node is nodeItem, the kids are left and right
   // usage:aptr = new (nothrow) Node (thisone, NULL, NULL);
   // CAUTION: REQUIRES THAT COPY WORKS IN ItemType!!
	AVLNode (const ItemType& nodeItem, AVLNode* left, AVLNode* right):
      item(nodeItem), leftP(left), rightP(right), height(0) {}
      
   // creates an empty node
   // post: the item of the node is empty and the kids are NULL
   // usage: newptr = new AVLNode();
   AVLNode (): leftP(NULL), rightP(NULL), height(0){}
   
   int getHeight(){
   	return height;
	}
   
private:
	ItemType item;
	AVLNode *leftP;
	AVLNode *rightP;
   int height;

   friend class AVLTree;

};
#endif
