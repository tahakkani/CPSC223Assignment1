#include "binarytree.h"
#include <iostream>
using namespace std;

	// creates a new binary tree that is a copy of an existing tree
	// post: object is a copy of rhstree
	// usage: BinaryTree zags (bulldog);
	BinaryTree::BinaryTree(const BinaryTree& rhstree){
		copyTree(mroot, rhstree.mroot);
	}

	// releases the memory of a binary tree
	// pre: object exists
	// post: memory for the object has been released. object theoretically does not exist
	//       but in practice, it is empty.
   BinaryTree::~BinaryTree(){
   	destroyTree(mroot);
	}
	

   // ******************** member functions ********************************************
   // pre: binary tree object exists
   // **********************************************************************************
   // post: returns true if the object is empty; else returns false
   // usage: if (tree.isEmpty())
   bool BinaryTree::isEmpty() const{
		if(mroot == NULL)
		  return true;
		return false;
	}

   // pre: rhstree is an assigned tree.
   // post: object is a copy of rhstree
   // usage: atree = btree = ctree;
   BinaryTree& BinaryTree::operator=(const BinaryTree& rhstree){
   	copyTree(mroot, rhstree.mroot);
	}

   // prints the tree to look like a computer science tree
   // post: outputs the tree as in the example below
   //
   //                        bar
   //                  foo
   //                        geeU
   //  root ->  queue
   //                        stack
   //                  list
   //                        array
   // nodes at the same level are indented the same.
   // Viewer must rotate head 90 degrees in order to look like a cs tree
   // usage: tree.PrettyDisplay();
   void BinaryTree::PrettyDisplay() const{
   	int level = 0;
		pDHelper(level, mroot);
	}
	

	void BinaryTree::pDHelper(int& lvl, Node* treep) const{
		if(treep == NULL)
			return;
		lvl++;
		pDHelper(lvl, treep->mrightptr);
		displayLine(lvl, treep);
		pDHelper(lvl, treep->mleftptr);
		lvl--;
	}
	

	void BinaryTree::displayLine(const int &lvl, Node* node) const{
		if(lvl == 1)
			cout << "root--> " << node->mitem << endl;
		else{
			cout << "    ";
			for(int tab = lvl; tab > 0; tab--)
				cout << "    ";
			cout << node->mitem << endl;
		}
	}

   // *************** on the following traversals
   // uses: operator<< from citem
   // post: prints the objects in the tree in order specified
   // usage: tree.PreorderTraverse();  
   // similarly for the other traversals
   // *****************************************************
	void BinaryTree::preorderTraverse () const{
		cout << "Pre-order traversal: ";
		preorder(mroot);
		cout << endl;
	}
   void BinaryTree::inorderTraverse () const{
   	cout << "In-order traversal: ";
		inorder(mroot);
		cout << endl;
	}
   void BinaryTree::postorderTraverse() const{
   	cout << "Post-order traversal: ";
      preorder(mroot);
      cout << endl;
	}

	// recursive helper functions for coding member functions
   


    // Copies one binary tree to another
    // pre: oldtreep points to the root of a binary tree
    // post: newtreep points to the root of a binary tree
    //  that has copies of the nodes of oldtreep's tree
    // usage: copyTree (newptr, oldptr);
    void BinaryTree::copyTree (Node*& newtreep, Node* oldtreep){
    	if(oldtreep == NULL)
    		newtreep == NULL;
    	else{
    		newtreep = new Node(oldtreep->mitem, NULL, NULL);
    		copyTree(newtreep->mleftptr, oldtreep->mleftptr);
    		copyTree(newtreep->mrightptr, oldtreep->mrightptr);
		 }	
	 } 

    // Releases memory for a binary tree
    // pre: treep points to the root of a binary tree
    // post: releases all of the nodes in the tree pointed to by treep
    //    and leaves treep empty.
    // usage: destroyTree (mroot);
    void BinaryTree::destroyTree (Node*& treep){
    	if(treep == NULL)
    		return;
    	else{
    		destroyTree(treep->mleftptr);
    		destroyTree(treep->mrightptr);
    		delete treep;
    		treep = NULL;
		 }	
	 }
/*

    // ********** recursive helpers for the traversals ****************
    // pre: treep points to the root of a binary tree to be traversed
    // post: prints the objects of the nodes on the screen in the 
    //     specified order
    // usage: preorder (mroot);   
    //    similarly for the others


*/
    void BinaryTree::preorder (Node* treep) const{
    	if(treep == NULL)
			return;
		cout << treep->mitem << " ";
		preorder(treep->mleftptr);
		preorder(treep->mrightptr);
	 }
    void BinaryTree::inorder (Node* treep) const{
    	if(treep == NULL)
			return;
		preorder(treep->mleftptr);
		cout << treep->mitem << " ";
		preorder(treep->mrightptr);
	 }
    void BinaryTree::postorder (Node* treep) const{
    	if(treep == NULL)
			return;
		preorder(treep->mleftptr);
		preorder(treep->mrightptr);
		cout << treep->mitem << " ";
	 }
	 
