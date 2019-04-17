#include "binarysearchtree.h"
#include <iostream>
using namespace std;

//////////////////////  DESTRUCTOR  //////////////////////////////////
   BinarySearchTree::~BinarySearchTree(){
		destroyTree(mroot);
	}

   bool BinarySearchTree::Search (const ItemType& theItem) const{
		lookup(mroot, theItem);
	}
   
   void BinarySearchTree::Insert (const ItemType& newItem){
   	insertItem(mroot, newItem);
	}
	
   void BinarySearchTree::remove (const ItemType& theItem){
   	removeItem(mroot, theItem);
	}
	
   Node * BinarySearchTree::FindMin() const{
		lookforMin(mroot);
	}
   Node * BinarySearchTree::FindMax() const{
		lookforMax(mroot);
	}
	
//////////////////// recursive helper functions /////////////////////////

   bool BinarySearchTree::lookup (Node * treeptr, const ItemType& theItem) const{
   	if(!treeptr)
			return false;
		else if(theItem == treeptr->mitem)
			return true;
		else if(theItem <= treeptr->mitem)
			lookup(treeptr->mleftptr, theItem);
		else if(theItem > treeptr->mitem)
			lookup(treeptr->mrightptr, theItem);
	}


   void BinarySearchTree::insertItem (Node *& treeptr, const ItemType& newItem){
   	if(!treeptr)
			treeptr = new Node(newItem, NULL, NULL);
		else if(newItem <= treeptr->mitem)
			insertItem(treeptr->mleftptr, newItem);
		else
			insertItem(treeptr->mrightptr, newItem);
	}
	

   void BinarySearchTree::removeItem (Node *& treeptr, const ItemType& theItem){
   	if(theItem < treeptr->mitem)
   		removeItem(treeptr->mleftptr, theItem);
		else if(theItem > treeptr->mitem)
			removeItem(treeptr->mrightptr, theItem);
		//The following cases, removeItem has found the node to be deleted
		else if(treeptr->mrightptr && treeptr->mleftptr){ //node to be deleted has two children
			Node *temp = treeptr->mleftptr;
			Node *del = treeptr;
			treeptr = treeptr->mrightptr;
			lookforMin(treeptr)->mleftptr = temp;
			delete del;
		}
		else if(!treeptr->mleftptr)
			treeptr = treeptr->mrightptr;
		else
			treeptr = treeptr->mleftptr;
	}


   Node * BinarySearchTree::lookforMin(Node * treeptr) const{
		Node * finder = treeptr;
		while(finder->mleftptr)
			finder = finder->mleftptr;
		return finder;
	}
	
   Node * BinarySearchTree::lookforMax(Node * treeptr) const{
		Node * finder = treeptr;
		while(finder->mrightptr)
			finder = finder->mrightptr;
		return finder;
	}
