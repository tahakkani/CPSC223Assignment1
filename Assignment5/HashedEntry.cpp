#include "HashedEntry.h"
HashedEntry::HashedEntry (){}

HashedEntry::~HashedEntry (){}

HashedEntry::HashedEntry (const KeyType & key, const ItemType & newEntry){
	searchKey = key;
  item = newEntry;
}

HashedEntry::HashedEntry (const KeyType & key, const ItemType & newEntry, HashedEntry *nextEntry){
	searchKey = key;
  item = newEntry;
  next = nextEntry;
}

void HashedEntry::setNext (HashedEntry *nextEntry){
  next = nextEntry;
}

HashedEntry* HashedEntry::getNext ()const{
  return next;
}
