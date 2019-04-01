#include "Entry.cpp"
#include "HashedEntry.cpp"
#include "HashedDictionary.cpp"

int main(){
	KeyType keys[3] = {0,1,2};
	ItemType items[3] = {"First ItemType", "Second Item Type", "Third Item Type"};
/*	Entry e(keys[0], items[0]);
	cout << e.getItem() << endl << e.getKey() << endl;
	e.setItem(items[1]);
	cout << e.getItem() << endl;
*//*
//Testing HashedEntry class
	//Constructors:
	HashedEntry hE1();
	HashedEntry hE2(keys[0], items[0]);
	HashedEntry hE3(keys[1], items[1]);
	HashedEntry hE4(keys[2], items[2], NULL);

	
	//Setters:
	HashedEntry *hPtr = &hE3;
	hE2.setNext(hPtr);
	hPtr = &hE4;
	hE3.setNext(hPtr);
	cout << hE2.getNext() << endl << hE3.getNext() << endl << hPtr->getNext();*/
	
	HashedDictionary hD;
    hD.add(keys[0], items[0]);
    hD.add(keys[0], items[1]);
    hD.add(keys[1], items[1]);
    hD.add(keys[2], items[2]);
    hD.display();
    hD.clear();
    hD.display();
}
