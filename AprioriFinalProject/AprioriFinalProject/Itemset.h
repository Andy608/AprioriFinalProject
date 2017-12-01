#ifndef ITEMSET_H
#define ITEMSET_H

class Itemset
{
	private:
		int mSizeOfItemset;
		int *mItems;

	public:
		Itemset();
		~Itemset();

		void createItemSet(int *items, int length);
};


#endif // !ITEMSET_H