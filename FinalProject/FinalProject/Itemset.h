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
	//Constants that will be used for the itemset objects
	int mSizeOfItemset;
	int *mItems;
	int mSupport;

public:
	/* Pre:		None
	*  Post:	Creates the default values for the vars
	*  Purpose: Creates the default values for the vars
	*****************************************************************************/
	Itemset();


	/* Pre:		Itemset object
	*  Post:	Copy constructor for the itemset
	*  Purpose: Copy the information from the one itemset into the other
	*****************************************************************************/
	Itemset(const Itemset& another);


	/* Pre:		an integer and the length
	*  Post:	Overloaded constructor of the itemset
	*  Purpose: Uses the given information and assigns the new vars
	*****************************************************************************/
	Itemset(int *items, int length);


	/* Pre:		None
	*  Post:	Deconstructs the pointers
	*  Purpose: Deconstructs the pointers
	*****************************************************************************/
	~Itemset();


	/* Pre:		None
	*  Post:	Gets the support var of the itemset
	*  Purpose: Returns the support var of the itemset
	*****************************************************************************/
	int getSupport() const;


	/* Pre:		None
	*  Post:	Gets the itemset
	*  Purpose: Gets the itemset and sets it up in {}
	*****************************************************************************/
	string getItemset() const;


	/* Pre:		None
	*  Post:	Incriment the support of the itemset
	*  Purpose: Incriment the support of the itemset
	*****************************************************************************/
	void incrementSupport();


	/* Pre:		None
	*  Post:	Gets the size of the itemset
	*  Purpose: Returns the size of the itemset
	*****************************************************************************/
	int getSizeOfItemset() const;


	/* Pre:		the first itemset, the second itemset, the size of the new itemset, and the linked list of the 
				new itemset
	*  Post:	Adds new itemsets to the overall itemset 
	*  Purpose: Adds each new itemset to the overall itemset linked list
	*****************************************************************************/
	static void addNewItemsets(Itemset& first, Itemset& second, int newItemsetSize, LinkedList<Itemset>& newItemsets);


	/* Pre:		the int item
	*  Post:	Makes the item object to the itemset
	*  Purpose: Adds a new item to the itemset
	*****************************************************************************/
	static Itemset Itemset::itemToItemset(const int& item);


	/* Pre:		Itemset
	*  Post:	Assigns itemset on right to the one on the left
	*  Purpose: Overloads assigment operator
	*****************************************************************************/
	void Itemset::operator=(Itemset &another);


	/* Pre:		Itemset
	*  Post:	Checks to see whether one itemset is equal to another
	*  Purpose: Checks to see whether the passed in itemset is equal to another itemset that it is comparing
				itself to
	*****************************************************************************/
	bool operator==(Itemset &another) const;


	/* Pre:		index number
	*  Post:	Gets the item at the index number
	*  Purpose: Gets the item at the index number
	*****************************************************************************/
	int getItemAtIndex(int index);


	/* Pre:		gets the output file and the itemset with all of the itemsets
	*  Post:	Outputs all the itemsets that are given
	*  Purpose: Outputs all the itemsets to the given output file
	*****************************************************************************/
	friend ostream& operator<<(ostream &output, Itemset itemset);
};

#endif // !ITEMSET_H