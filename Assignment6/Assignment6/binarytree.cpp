#include "binarytree.h"
#include <iostream>
using namespace std;


	BinaryTree::BinaryTree(const BinaryTree& rhstree){
		copyTree(mroot, rhstree.mroot);
	}

   BinaryTree::~BinaryTree(){
   	destroyTree(mroot);
	}
	
   bool BinaryTree::isEmpty() const{
		if(mroot == NULL)
		  return true;
		return false;
	}

   BinaryTree& BinaryTree::operator=(const BinaryTree& rhstree){
   	copyTree(mroot, rhstree.mroot);
	}
	
/*************DISPLAY FUNCTIONS**********************************/

   void BinaryTree::PrettyDisplay() const{
   	int level = 0;
		pDHelper(level, mroot);
		cout << endl << endl;
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
/*********************************************************************/

   // *************** traversals ******************

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

/*****	// recursive helper functions for coding member functions   *******/

    void BinaryTree::copyTree (Node*& newtreep, Node* oldtreep){
    	if(oldtreep == NULL)
    		newtreep == NULL;
    	else{
    		newtreep = new Node(oldtreep->mitem, NULL, NULL);
    		copyTree(newtreep->mleftptr, oldtreep->mleftptr);
    		copyTree(newtreep->mrightptr, oldtreep->mrightptr);
		 }	
	 } 

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


    // ********** recursive helpers for the traversals ****************

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
	 
