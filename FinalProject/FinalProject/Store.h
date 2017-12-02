#ifndef STORE_H
#define STORE_H
#include <iostream>
using namespace std;

class Store
{
private:

	static const int SIZE_INCREMENT = 1000;

	string mStoreFileName;
	int *mItems;
	int mCapacity;
	int mNumberOfItems;

	void setCapacity(int capacity);
	void addItemToList(int itemID);

public:

	static const int BAD_ID;

	Store();
	~Store();

	int getNumberOfItems() const;

	string getStoreFileName() const;
	void setStoreFileName(string storeName);

	bool createItemList();
	const int& getItemByID(const int &itemID) const;
};

#endif // !STORE_H