#include "Entry.h"
#include <iostream>

Entry::Entry(){}

Entry::Entry(KeyType & key, ItemType & newEntry){
  searchKey = key;
  item = newEntry;
}

Entry::~Entry(){}

ItemType Entry::getItem() const{
  return item;
}

KeyType Entry::getKey() const{
  return searchKey;
}

void Entry::setItem (const ItemType & newEntry){
  item = newEntry;
}
