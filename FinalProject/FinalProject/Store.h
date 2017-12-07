#ifndef STORE_H
#define STORE_H

#include <iostream>
#include "ShoppingCart.h"

using namespace std;

class Store
{
private:
	//Creates the default values for the store
	//Creates the size of the store multiplying it by 1000
	//to account for parsing the file name
	static const int SIZE_INCREMENT = 1000;

	string mStoreFileName;
	int *mItems;
	int mCapacity;
	int mNumberOfItems;

	/*      Pre:  integer capacity of the store
	*     Post:  Sets the capacity of the store with the passed in value
	*  Purpose:  Sets the capacity of the store with the passed in value
	************************************************************************/
	void setCapacity(int capacity);
	/*      Pre:  The itemID 
	*     Post:  Adds the new item to the store
	*  Purpose:  Adds the items to thhe store objects
	************************************************************************/
	void addItemToList(int itemID);

public:
	//Bad id item, meaning already exists
	static const int BAD_ID;

	/*      Pre:  None
	*     Post:   default constructor
	*  Purpose:  To initialize data object
	************************************************************************/
	Store();
	/*      Pre:  None
	*     Post:   default deconstructor
	*  Purpose:   To delete all the pointers
	************************************************************************/
	~Store();

	/*      Pre:  None
	*     Post:   gets the number of items in the store
	*  Purpose:  returns the number of items in the store
	************************************************************************/
	int getNumberOfItems() const;

	/*      Pre:  None
	*     Post:	  Gets the store file name
	*  Purpose:   Returns the store name to the program
	************************************************************************/
	string getStoreFileName() const;
	/*      Pre:  string of Storename
	*     Post:   sets the name of the store
	*  Purpose:   Sets the name of the store
	************************************************************************/
	void setStoreFileName(string storeName);

	/*      Pre:  shopping cart length
	*     Post:   creates the store while passing the shopping cart length
	*  Purpose:   Creates the store with passed in values
	************************************************************************/
	bool createStore(int& shoppingCartLength);
	/*      Pre:  itemID
	*     Post:	  gets the item id in the store
	*  Purpose:   returns the item id
	************************************************************************/
	const int& getItemByID(const int &itemID) const;
	/*      Pre:  index of the item
	*     Post:   gets the item by the index
	*  Purpose:   Retruns the item at the index given
	************************************************************************/
	const int& getItemByIndex(int index) const;
};

#endif // !STORE_H