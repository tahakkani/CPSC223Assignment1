/** @file ListNode.h */
#ifndef _LISTNODE
#define _LISTNODE

typedef int ItemType;

class ListNode
{
    public:
           ItemType getItem();
           ListNode *getNext();
           ListNode();
           ListNode(const ItemType & x);
           ListNode(const ItemType & x, ListNode * nNode);
           void setNext(ListNode * nNode);
           void setItem(const ItemType & x);
           ~ListNode();

    private :
            ItemType item; // A data item
            ListNode * next; // Pointer to next node
    friend class ListP;
}; // end Node

#endif
