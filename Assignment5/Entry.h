#ifndef _ENTRY
#define _ENTRY
#include<string>
using namespace std;

typedef string ItemType;
typedef int KeyType;

class Entry
{
protected:
  ItemType item;
  KeyType searchKey;

public:
  Entry();
  Entry(KeyType & key, ItemType & newEntry);
  ~Entry();
  ItemType getItem () const;

  KeyType getKey () const;

  void setItem (const ItemType & newEntry);
};// end Entry

#endif
