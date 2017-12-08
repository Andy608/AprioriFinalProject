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

#ifndef HEADER_H
#define HEADER_H

#include <sstream>
#include "Itemset.h"
#include "LinkedList.h"
#include "ShoppingCart.h"
#include "Store.h"

//constants used in the program
const int MINIMUM_SUPPORT = 3;
const string EXIT = "exit";

/* Pre:		The store object, the shopping cart object, the size of the shopping carts, and the total itemsets
*  Post:	Uses apriori algorithm to find frequent itemsets
*  Purpose: Looks through all of the item sets given to it and then makes candidate itemsets that pass the minimum support constant
*****************************************************************************/
void apriori(const Store& store, ShoppingCart* shoppingCarts, int shoppingCartSize, LinkedList<Itemset>& totalItemsets);


/* Pre:		The store object and the shopping cart object
*  Post:	Creates the shopping carts that will be used for the apriori algorithm
*  Purpose: Creates the shopping carts from the items inside of the store object
*****************************************************************************/
void createShoppingCarts(Store &store, ShoppingCart *shoppingCarts);


/* Pre:		The shopping cart object, the shopping cart size the linked list of the previous itemsets, the linked
			list of the next itemsets, the linked list of the candidate item sets, and the linked list of the total itemsets
*  Post:	Generates the frequent itemsets that are passed into the function
*  Purpose: Generate the frequent itemsets that are passed into the function through the shopping cart class and then placing
			then into a linked list to store the information of the reoccuring frequent items
*****************************************************************************/
void generateFrequentNItemsets(ShoppingCart* shoppingCarts, int shoppingCartSize, LinkedList<Itemset>& previousItemsets,
	LinkedList<Itemset>& nextItemsets, LinkedList<Itemset>& candidateItemsets, LinkedList<Itemset>& totalItemsets);


/* Pre:		The store object, the shopping cart object, the size of the shopping carts, the frequent one itemset and the
			total itemset
*  Post:	Generates the frequent itemset for the 1st itemset
*  Purpose: Generate the frequent itemset that are passed into the function through the shopping cart class and then placing
then into a linked list to store the information of the reoccuring frequent items
*****************************************************************************/
void generateFrequentOneItemsets(const Store& store, ShoppingCart* shoppingCarts, int shoppingCartSize, 
								 LinkedList<Itemset> &freqOneItemsets, LinkedList<Itemset>& totalItemsets);


/* Pre:		The inputFilename and the output file name
*  Post:	Gets the filename and opens them so the program can use the information inside of them
*  Purpose: To open the filenames tthat the user gives the program
*****************************************************************************/
void getFilename(string& inputFile, string& outputFile);


/* Pre:		The itemset and the filename
*  Post:	Outputs the frequent itemset to the output file
*  Purpose: Outputs the frequent itemset to the output file
*****************************************************************************/
void outputFrequentItemsets(LinkedList<Itemset> itemsetOutput, string& outputFilename);


/* Pre:		The lowerbound, and upperbound index.
*  Post:	Sorts the list of data in decending to ascending order.
*  Purpose: To sort a list of data.
*****************************************************************************/
template <typename T>
void quickSort(T* arr, int lowerBound, int upperBound)
{
	int leftCounter = lowerBound;
	int rightCounter = upperBound;
	T pivot = arr[(leftCounter + rightCounter) / 2];

	while (leftCounter <= rightCounter)
	{
		while (arr[leftCounter] < pivot)
		{
			++leftCounter;
		}

		while (arr[rightCounter] > pivot)
		{
			--rightCounter;
		}

		if (leftCounter <= rightCounter)
		{
			T temp = arr[rightCounter];
			arr[rightCounter] = arr[leftCounter];
			arr[leftCounter] = temp;

			++leftCounter;
			--rightCounter;
		}
	}

	if (lowerBound < rightCounter)
	{
		quickSort(arr, lowerBound, rightCounter);
	}

	if (leftCounter < upperBound)
	{
		quickSort(arr, leftCounter, upperBound);
	}
}

#endif // !HEADER_H