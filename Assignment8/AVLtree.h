// Specification of AVL Tree
//    Data object: An AVL Tree T that is either empty or in the form
//		you finish.

//    Operations: (a scaled-down version)
//    	   Search, Insert, lookup, insertItem
// 	Contract: Assumes the this class can access private data members of class   Node.
//    		Those data members are: citem mitem, c AVLNode* mleftptr, c AVLNode* mrightptr.
//
#ifndef AVLTREE_H
#define AVLTREE_H
#include "AVLNode.h"

class AVLTree
{
public:
	/********************************************************************
	**************    CONSTRUCTORS   ************************************
	********************************************************************/
	// creates an empty binary tree
	// post: object is an empty AVL tree
	// usage: AVLTree zags;
	AVLTree():root(NULL){};

	// creates a AVL tree with exactly one  AVLNode, namely the root
	//post: BT with one  AVLNode with left, right ==NULL
	//usage: AVLTree(myItem);
	AVLTree(const ItemType& rootItem):root(new AVLNode(rootItem, NULL, NULL)){};

	// links two AVL trees together
	// pre: two BTs and an ItemType exist
	//post: the two BTs become the left and right children of a  AVLNode with the ItemType
	//usage: AVLTree(rootItem, myTree1, myTree2);
	AVLTree(const ItemType& rootItem,AVLTree& leftTree, AVLTree& rightTree);

	// creates a new AVL tree that is a copy of an existing tree
	// post: object is a copy of rhstree
	// usage: AVLTree zags (bulldog);
	AVLTree(const AVLTree& rhstree);



	// releases the memory of a AVL tree
	// pre: object exists
	// post: memory for the object has been released. object theoretically does not exist
	//       but in practice, it is empty.
   ~AVLTree();

   // ******************** member functions ********************************************
   // pre: AVL tree object exists
   // **********************************************************************************
   // post: returns true if the object is empty; else returns false
   // usage: if (tree.isEmpty())
   bool isEmpty() const;

   // pre: rhstree is an assigned tree.
   // post: object is a copy of rhstree
   // usage: atree = btree = ctree;
   AVLTree& operator=(const AVLTree& rhstree);

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
   //  AVLNodes at the same level are indented the same.
   // Viewer must rotate head 90 degrees in order to look like a cs tree
   // usage: tree.PrettyDisplay();
   void PrettyDisplay() const;

   // *****************************************************

   void preorderTraverse () const;
   void inorderTraverse () const;
   void postorderTraverse() const;

//protected:   // recursive helper functions for coding member functions

    // Copies one AVL tree to another
    // pre: oldtreep points to the root of a AVL tree
    // post: newtreep points to the root of a AVL tree
    //  that has copies of the  AVLNodes of oldtreep's tree
    // usage: copyTree (newptr, oldptr);
    void copyTree ( AVLNode*& newtreep,  AVLNode* oldtreep);

    // Releases memory for a AVL tree
    // pre: treep points to the root of a AVL tree
    // post: releases all of the  AVLNodes in the tree pointed to by treep
    //    and leaves treep empty.
    // usage: destroyTree (root);
    void destroyTree ( AVLNode*& treep);

    // recursive helper for prettyDisplay. Order: Right subtree, center, left subtree
    //pre:   root points to AVL tree to be printed. lvl ALWAYS == 0.
    //post:  AVL tree displayed line by line
    //usage: pDHelper(level, root);
	void pDHelper(int& lvl,  AVLNode* treep) const;

		//helper function for prettyDisplayHelper.
	//pre:  pDHelper gives the current level and  AVLNode at that level
	//post: tabs the correct number of times (based on level) so as
	//      to give the appearance of a tree, displays item at  AVLNode
	//
	//usage: displayLine(lvl, treep);
	void displayLine(const int &lvl, AVLNode* node) const;

    // ********** recursive helpers for the traversals ****************
    // pre: treep points to the root of a AVL tree to be traversed
    // post: prints the objects of the  AVLNodes on the screen in the
    //     specified order
    // usage: preorder (root);
    //    similarly for the others

    void preorder (AVLNode* treep) const;
    void inorder (AVLNode* treep) const;
    void postorder (AVLNode* treep) const;

   // *****************************************************************
   // *  pre for all member functions: AVL search tree object exists
   // *****************************************************************

   //@recursively searches for an ItemType in a AVL search tree object and
   //    retrieves it
   //@pre: ItemType has been assigned.
   //@post:If ItemType is in the AVL tree, return true, else return false
   //@usage: bst.Search (myItem);
   bool Search (const ItemType& theItem) const;

   //@inserts a new item into the AVL search tree
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
	//@post: If the BST object has atleast one  AVLNode,
	//			a  AVLNode* pointing to the smallest/largest
	//			item is returned.
	//       If BST object is empty, return NULL
	//@usage: FindMin();
   AVLNode * FindMin() const;
   AVLNode * FindMax() const;
   ////////////////////////////////////////////////////////////////////////////////
  // recursive helper functions
   //@recursively searches (modeling on AVL search) for an item
   //@pre: treeptr is assigned. theItem is assigned.
   //@post: searches for the item in the tree with treeptr's root.
   //    If theItem is found, return true, else false.
   //@usage: lookup (root, rest);
   bool lookup (AVLNode * treeptr, const ItemType& theItem) const;

   //@ helper for Insert(const ItemType&)
	//@pre: treeptr and newItem has been assigned
	//@post: newItem location is recursively found.
	//@usage: insertItem(root, theItem);
   void insertItem (AVLNode *& treeptr, const ItemType& newItem);
   void setHeight(AVLNode *treeptr);
   Node* rotateWithLeftChild(Node* k2);
   Node* rotateWithRightChild(Node* k2);
   Node* doubleRotateWithLeftChild(Node* k3);
   Node* doubleRotateWithRightChild(Node* k1);


	//@ helper for Remove(const ItemType&)
	//@pre: treeptr and newItem has been assigned
	//@post: newItem location is recursively found and removed.
	//@usage: removeItem(root, theItem);
   void removeItem (AVLNode *& treeptr, const ItemType& theItem);

	/////////////////////////////////////////////////////////////////////
	//used in FindMin()/FindMax() and removeItem
	//pre: treeptr is a BST
	//post: returns the min/max item in treep. If empty, returns NULL
	//usage: lookforMin(treeptr); lookforMax(treeptr);
   AVLNode * lookforMin(AVLNode * treeptr) const;
   AVLNode * lookforMax(AVLNode * treeptr) const;
   //////////////////////////////////////////////////////////////////////
   
    // data member

	bool isBalanced (AVLNode *node);
	
    AVLNode* root;
};
#endif
