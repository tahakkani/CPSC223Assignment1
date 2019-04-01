#include "HashedDictionary.h"
#include <iostream>

int HashedDictionary::hashFunc (const KeyType & key){
	return key % DEFAULT_SIZE;
}

HashedDictionary::HashedDictionary(){
		itemCount = 0;
		hashTableSize = 0;
		
		for(int i = 0; i < DEFAULT_SIZE; i++){
			hashTable[i] = NULL;
		}
	}

HashedDictionary::~ HashedDictionary (){
}

bool HashedDictionary::isEmpty () const{
  for(int i = 0; i < DEFAULT_SIZE; i++){
  	if(hashTable[i] != NULL)
  	  return false;
  } 
  return true;
}

  int HashedDictionary::getNumberOfItems () const{
    return itemCount;
  }

  void HashedDictionary::add (const KeyType & key, const ItemType & newItem){
		HashedEntry *p = new HashedEntry(key, newItem, NULL);
		int i = hashFunc(key);
		if(hashTable[i] == NULL){
			hashTable[i] = p;
			hashTableSize++;
		}
		else{
			HashedEntry *curr = hashTable[i];
			cout << curr->getNext();
			while(curr->getNext()){
				curr = curr->getNext();
			}
			curr->setNext(p);
		}
		itemCount++;
	}

  bool HashedDictionary::remove (const KeyType & key){
  	int i = hashFunc(key);
  	if(hashTable[i] != NULL){
  		if(hashTable[i]->getKey() == key){
  			HashedEntry *temp = hashTable[i];
  			hashTable[i] = hashTable[i]->getNext();
  			delete temp;
  			itemCount--;
  			if(hashTable[i] == NULL)
  				hashTableSize--;
		  }
		else{
			HashedEntry *curr = hashTable[i]->getNext(), *prev = hashTable[i];
			while(curr){
				if(curr->getKey() == key){
					prev->setNext(curr->getNext());
					delete curr;
					itemCount--;
					return true; 
				}
			}
		} 
	  }
	return false;  
  }

  void HashedDictionary::clear (){
  	for(int i = 0; i < DEFAULT_SIZE; i++){
  		while(hashTable[i]){
  			HashedEntry *temp = hashTable[i];
  			hashTable[i]->setNext(hashTable[i]->getNext());
  			delete temp;
		  }
	  }
  }

  ItemType HashedDictionary::search (const KeyType & key) const{}

  bool HashedDictionary::contains (const KeyType & key) const{}
  
  void HashedDictionary::display(){
		for(int i = 0; i < DEFAULT_SIZE; i++){
			cout << "[" << i << "]: ";
			HashedEntry *curr = hashTable[i];
			while(curr){
				cout << "(" << curr->getItem() << ", "<< curr->getKey() << ") -> ";
				curr = curr->getNext();
			}
			cout << endl;
		}
	}
