// Specification of ADT Binary Search Tree
//    Data object: A binary search tree T that is either empty or in the form
//		you finish.

//    Operations: (a scaled-down version)
//    	   Search, Insert, lookup, insertItem
// 	Contract: Assumes the this class can access private data members of class cnode.
//    		Those data members are: citem mitem, cnode* mleftptr, cnode* mrightptr.
//    
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "binarytree.h"
#include "node.h"

class BinarySearchTree: public BinaryTree
{
public:
   //@creates a new binary search tree
   //@post: an empty binary search tree object exists
   //@usage: BinarySearchTree bst;
   BinarySearchTree(){};

   //@releases memory for a binary search tree
   //@pre: binary search tree object exists
   //@post: binary search tree object does not exist
   //@usage: automatically done at end of scope
   ~BinarySearchTree();

   // *****************************************************************
   // *  pre for all member functions: binary search tree object exists
   // *****************************************************************

   //@recursively searches for an ItemType in a binary search tree object and
   //    retrieves it
   //@pre: ItemType has been assigned.
   //@post:If ItemType is in the binary tree, return true, else return false
   //@usage: bst.Search (myItem);
   bool Search (const ItemType& theItem) const;

   //@inserts a new item into the binary search tree
   //@pre: newItem has been assigned
   //@post: if the newItem's key is not already in the tree
   //       and there is memory available
   //         then the newItem is added to the tree
   //       else an exception is thrown
   //@usage: bst.Insert(myItem);
   void Insert (const ItemType& newItem);
   
	//@removes an item already in the BST
	//@pre: theItem has been assigned
	//@post: if theItem is in the BST, it will be removed.
	//       Else, an exception will be thrown
	//@usage: remove(theItem);
   void remove (const ItemType& theItem);
   
   ////////////////////////////////////////////////////////////////////////////////
	//@finds the smallest/largest item in the BST
	//@pre: BST object exists
	//@post: If the BST object has atleast one node,
	//			a Node* pointing to the smallest/largest
	//			item is returned.
	//       If BST object is empty, return NULL
	//@usage: FindMin();
   Node * FindMin() const;
   Node * FindMax() const;
   ////////////////////////////////////////////////////////////////////////////////

protected:  // recursive helper functions
   //@recursively searches (modeling on binary search) for an item
   //@pre: treeptr is assigned. theItem is assigned.
   //@post: searches for the item in the tree with treeptr's root.
   //    If theItem is found, return true, else false.
   //@usage: lookup (mroot, rest);
   bool lookup (Node * treeptr, const ItemType& theItem) const;

   //@ helper for Insert(const ItemType&)
	//@pre: treeptr and newItem has been assigned
	//@post: newItem location is recursively found.
	//@usage: insertItem(mroot, theItem);
   void insertItem (Node *& treeptr, const ItemType& newItem);
   
	//@ helper for Remove(const ItemType&)
	//@pre: treeptr and newItem has been assigned
	//@post: newItem location is recursively found and removed.
	//@usage: removeItem(mroot, theItem);
   void removeItem (Node *& treeptr, const ItemType& theItem);
   
	/////////////////////////////////////////////////////////////////////
	//used in FindMin()/FindMax() and removeItem
	//pre: treeptr is a BST
	//post: returns the min/max item in treep. If empty, returns NULL
	//usage: lookforMin(treeptr); lookforMax(treeptr);
   Node * lookforMin(Node * treeptr) const;
   Node * lookforMax(Node * treeptr) const;
   //////////////////////////////////////////////////////////////////////
};
#endif
