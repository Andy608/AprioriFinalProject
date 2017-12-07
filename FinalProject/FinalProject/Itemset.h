/*
Author: Walter Hill, Andrew Rimpici, Kelly Herstine
Class: Data Structures & Algorithims (CSI 281-01)
Assignment: Apriori Final Project
Date Assigned: 11/16/17
Due Date: 12/8/17

Program Description: Final Project - Apriori Program

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given fully-documented references to the work of others.
I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may,
for the purpose of assessing this assignment:- Reproduce this assignment and provide a copy to another member of
academic staff; and/or - Communicate a copy of this assignment to a plagiarism checking service
(which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking)
*/


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