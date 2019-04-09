#include "binarysearchtree.h"
#include <iostream>
using namespace std;

   //@releases memory for a binary search tree
   //@pre: binary search tree object exists
   //@post: binary search tree object does not exist
   //@usage: automatically done at end of scope
   BinarySearchTree::~BinarySearchTree(){
		destroyTree(mroot);
	}

   // *****************************************************************
   // *  pre for all member functions: binary search tree object exists
   // *****************************************************************

   //@searches for a key in a binary search tree object and
   //    retrieves the corresponding item
   //@pre: key has been assigned.
   //@post: theItem contains tkey with rest of the item if
   //    tkey is found in the binary search tree object
   //    else an exception is thrown
   //@usage: bst.Retrieve (abbrev, meaning);
   bool BinarySearchTree::Search (const ItemType& theItem) const{
		lookup(mroot, theItem);
	}
   
   //@inserts a new item into the binary search tree
   //@pre: newItem has been assigned
   //@post: if the newItem's key is not already in the tree
   //       and there is memory available
   //         then the newItem is added to the tree
   //       else an exception is thrown
   //@usage: bst.Insert(myItem);
   void BinarySearchTree::Insert (const ItemType& newItem){
   	insertItem(mroot, newItem);
	}
//   void BinarySearchTree::remove (const ItemType& theItem);
   Node * BinarySearchTree::FindMin() const{
		lookforMin(mroot);
	}
   Node * BinarySearchTree::FindMax() const{
		lookforMax(mroot);
	}

// recursive helper functions
   //@recursively searches (modeling on binary search) for an item
   //@pre: treeptr is assigned. newItem is assigned.
   //@post: searches for the item in the tree with treeptr's root.
   //    If theItem is found, return true, else false.
   //@usage: retrieveItem (mroot, rest);
   bool BinarySearchTree::lookup (Node * treeptr, const ItemType& theItem) const{
   	if(!treeptr)
			return false;
		else if(theItem == treeptr->mitem)
			return true;
		else if(theItem <= treeptr->mitem)
			lookup(treeptr->mleftptr, theItem);
		else
			lookup(treeptr->mrightptr, theItem);
	}

   // write the documentation
   void BinarySearchTree::insertItem (Node *& treeptr, const ItemType& newItem){
   	if(!treeptr)
			treeptr = new Node(newItem, NULL, NULL);
		else if(newItem <= treeptr->mitem)
			insertItem(treeptr->mleftptr, newItem);
		else
			insertItem(treeptr->mrightptr, newItem);
	}
//   void BinarySearchTree::removeItem (Node *& treeptr, const ItemType& theItem);

	////////////////////////////////////////////////////////
	//used in FindMin()/FindMax() and removeItem
	//pre: treeptr is a BST
	//post: returns the min/max item in treep. If empty, returns NULL
	//usage: lookforMin(treeptr); lookforMax(treeptr);
   Node * BinarySearchTree::lookforMin(Node * treeptr) const{
		Node * finder = treeptr;
		while(finder)
			finder = finder->mleftptr;
		return finder;
	}
	
   Node * BinarySearchTree::lookforMax(Node * treeptr) const{
		Node * finder = treeptr;
		while(finder)
			finder = finder->mrightptr;
		return finder;
	}
   //Prune's helpers shear etc go here else remove this

