#ifndef ITEMSET_H
#define ITEMSET_H

#include <string>
#include "LinkedList.h"
using namespace std;

class Itemset
{
private:
	int mSizeOfItemset;
	int *mItems;
	int mSupport;

public:
	Itemset();
	Itemset(Itemset& another);
	Itemset(int *items, int length);
	~Itemset();

	int getSupport() const;
	string getItemset() const;
	void incrementSupport();
	int getSizeOfItemset() const;
	static void addNewItemsets(Itemset& first, Itemset& second, int newItemsetSize, LinkedList<Itemset>& newItemsets);

	bool operator==(Itemset another) const;
	int getItemAtIndex(int index);

	friend ostream& operator<<(ostream &output, Itemset itemset);
};


#endif // !ITEMSET_H