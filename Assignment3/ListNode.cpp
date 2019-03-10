
#include "ListNode.h"
#include <iostream>
using namespace std;

ItemType ListNode::getItem(){return item;}
ListNode* ListNode::getNext(){return next;}
ListNode::ListNode(){
	next = NULL;
}
ListNode::ListNode(const ItemType & x){
	item = x;
	next = NULL;
}
ListNode::ListNode(const ItemType & x, ListNode * nNode){
	item = x;
	next = nNode;
}
void ListNode::setNext(ListNode * nNode){
	next = nNode;
}
void ListNode::setItem(const ItemType & x){
	item = x;
}
ListNode::~ListNode(){
}
