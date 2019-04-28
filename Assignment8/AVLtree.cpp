#include "AVLtree.h"
#include <iostream>
#include <cstdlib>
using namespace std;

	AVLTree::AVLTree(const ItemType& rootItem,AVLTree& leftTree, AVLTree& rightTree){
		root = new AVLNode(rootItem, leftTree.root, rightTree.root);
	}
	
	AVLTree::AVLTree(const AVLTree& rhstree){
		copyTree(root, rhstree.root);
	}

   bool AVLTree::isEmpty() const{
		if(root == NULL)
		  return true;
		return false;
	}

   AVLTree& AVLTree::operator=(const AVLTree& rhstree){
   	copyTree(root, rhstree.root);
	}

/*************DISPLAY FUNCTIONS**********************************/

   void AVLTree::PrettyDisplay() const{
   	int level = 0;
		pDHelper(level, root);
		cout << endl << endl;
	}

	void AVLTree::pDHelper(int& lvl, AVLNode* treep) const{
		if(treep == NULL)
			return;
		lvl++;
		pDHelper(lvl, treep->rightP);
		displayLine(lvl, treep);
		pDHelper(lvl, treep->leftP);
		lvl--;
	}

	void AVLTree::displayLine(const int &lvl, AVLNode* node) const{
		if(lvl == 1)
			cout << "root--> " << node->item;
		else{
			cout << "    ";
			for(int tab = lvl; tab > 0; tab--)
				cout << "    ";
			cout << node->item;
		}
		cout << "("<<node->getHeight()<<")"<< endl;
	}
/*********************************************************************/

   // *************** traversals ******************

	void AVLTree::preorderTraverse () const{
		cout << "Pre-order traversal: ";
		preorder(root);
		cout << endl;
	}
   void AVLTree::inorderTraverse () const{
   	cout << "In-order traversal: ";
		inorder(root);
		cout << endl;
	}
   void AVLTree::postorderTraverse() const{
   	cout << "Post-order traversal: ";
      preorder(root);
      cout << endl;
	}

/*****	// recursive helper functions for coding member functions   *******/

    void AVLTree::copyTree (AVLNode*& newtreep, AVLNode* oldtreep){
    	if(oldtreep == NULL)
    		newtreep == NULL;
    	else{
    		newtreep = new AVLNode(oldtreep->item, NULL, NULL);
    		copyTree(newtreep->leftP, oldtreep->leftP);
    		copyTree(newtreep->rightP, oldtreep->rightP);
		 }
	 }

    void AVLTree::destroyTree (AVLNode*& treep){
    	if(treep == NULL)
    		return;
    	else{
    		destroyTree(treep->leftP);
    		destroyTree(treep->rightP);
    		delete treep;
    		treep = NULL;
		 }
	 }


    // ********** recursive helpers for the traversals ****************

    void AVLTree::preorder (AVLNode* treep) const{
    	if(treep == NULL)
			return;
		cout << treep->item << " ";
		preorder(treep->leftP);
		preorder(treep->rightP);
	 }
    void AVLTree::inorder (AVLNode* treep) const{
    	if(treep == NULL)
			return;
		preorder(treep->leftP);
		cout << treep->item << " ";
		preorder(treep->rightP);
	 }
    void AVLTree::postorder (AVLNode* treep) const{
    	if(treep == NULL)
			return;
		preorder(treep->leftP);
		preorder(treep->rightP);
		cout << treep->item << " ";
	 }
	 
//////////////////////  DESTRUCTOR  //////////////////////////////////
   AVLTree::~AVLTree(){
		destroyTree(root);
	}

   bool AVLTree::Search (const ItemType& theItem) const{
		lookup(root, theItem);
	}

   void AVLTree::Insert (const ItemType& newItem){
   	insertItem(root, newItem);
	}

   void AVLTree::remove (const ItemType& theItem){
   	removeItem(root, theItem);
	}

   AVLNode * AVLTree::FindMin() const{
		lookforMin(root);
	}
   AVLNode * AVLTree::FindMax() const{
		lookforMax(root);
	}
	
	

//////////////////// recursive helper functions /////////////////////////

   bool AVLTree::lookup (AVLNode * treeptr, const ItemType& theItem) const{
   	if(!treeptr)
			return false;
		else if(theItem == treeptr->item)
			return true;
		else if(theItem <= treeptr->item)
			lookup(treeptr->leftP, theItem);
		else if(theItem > treeptr->item)
			lookup(treeptr->rightP, theItem);
	}


   void AVLTree::insertItem (AVLNode *& treeptr, const ItemType& newItem){
   	if(!treeptr)
			treeptr = new AVLNode(newItem, NULL, NULL);
		else if(newItem <= treeptr->item){
			insertItem(treeptr->leftP, newItem);
			setHeight(treeptr);
		}
		else{
			insertItem(treeptr->rightP, newItem);
			setHeight(treeptr);
		}
		if(abs(getBal(treeptr)) > 1){
			if(getBal(treeptr) < 0){
				if(getBal(treeptr->leftP) < 0){
					treeptr = rotateWithLeftP(treeptr);
				}
				else{
					treeptr = doubleRotateWithLeftP(treeptr);
				}
			}
			else if(getBal(treeptr->rightP) > 0)
					treeptr = rotateWithRightP(treeptr);
				else
					treeptr = doubleRotateWithRightP(treeptr);
		}
	}
	int AVLTree::getBal(AVLNode *node) const{
		int l,r;
		if(node->leftP)
			l = node->leftP->height;
		else
			l = -1;
		if(node->rightP)
			r = node->rightP->height;
		else
			r = -1;
		return (r - l);
	}

	//update height on the following functions
	AVLNode* AVLTree::rotateWithLeftP(AVLNode* k2){
		 AVLNode* k1 = k2->leftP;
		 k2->leftP = k1->rightP;
		 k1->rightP = k2;
		 setHeight(k2);
		 setHeight(k1);
		 return k1;
	}
   AVLNode* AVLTree::rotateWithRightP(AVLNode* k1){
		 AVLNode * k2 = k1->rightP;
		 k1->rightP = k2->leftP;
		 k2->leftP = k1;
		 setHeight(k1);
		 setHeight(k2);
		 return k2;
	}
   AVLNode* AVLTree::doubleRotateWithLeftP(AVLNode* k3){
		 k3->leftP = rotateWithRightP(k3->leftP);
		 return rotateWithLeftP(k3);
	}
   AVLNode* AVLTree::doubleRotateWithRightP(AVLNode* k1){
		 k1->rightP = rotateWithLeftP(k1->rightP);
		 return rotateWithRightP(k1);
	}
	
////////////////////////////////////////////////////////////////
	void AVLTree::setHeight(AVLNode *treeptr){
		if(treeptr->leftP && treeptr->rightP)
			treeptr->height = max(treeptr->leftP->getHeight(), treeptr->rightP->getHeight()) + 1;
		else if(treeptr->leftP)
			treeptr->height = treeptr->leftP->height + 1;
		else if(treeptr->rightP)
			treeptr->height = treeptr->rightP->height + 1;
		else
			treeptr->height = 0;
	}

	int max(int a, int b){
		if (a > b)
			return a;
		return b;
	}

   void AVLTree::removeItem (AVLNode *& treeptr, const ItemType& theItem){
   	if(theItem < treeptr->item)
   		removeItem(treeptr->leftP, theItem);
		else if(theItem > treeptr->item)
			removeItem(treeptr->rightP, theItem);
		//The following cases, removeItem has found the AVLNode to be deleted
		else if(treeptr->rightP && treeptr->leftP){ //node to be deleted has two children
			AVLNode *temp = treeptr->leftP;
			AVLNode *del = treeptr;
			treeptr = treeptr->rightP;
			lookforMin(treeptr)->leftP = temp;
			delete del;
		}
		else if(!treeptr->leftP)
			treeptr = treeptr->rightP;
		else
			treeptr = treeptr->leftP;
	}


   AVLNode * AVLTree::lookforMin(AVLNode * treeptr) const{
		AVLNode * finder = treeptr;
		while(finder->leftP)
			finder = finder->leftP;
		return finder;
	}

   AVLNode * AVLTree::lookforMax(AVLNode * treeptr) const{
		AVLNode * finder = treeptr;
		while(finder->rightP)
			finder = finder->rightP;
		return finder;
	}
	 
	 

bool AVLTree::isBalanced (AVLNode *node){
	if(!node->leftP && !node->rightP)
		return true;
	else if(!node->leftP){
		if(node->rightP->getHeight() > 0)
			return false;
		return true;
	}
	else if(!node->rightP){
		if(node->leftP->getHeight() > 0)
			return false;
		return true;
	}
	else if(abs(node->leftP->height - node->rightP->height) > 1)
		return false;
	return true;
}
