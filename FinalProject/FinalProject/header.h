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

const int MINIMUM_SUPPORT = 3;
const string EXIT = "exit";

void apriori(const Store& store, ShoppingCart* shoppingCarts, int shoppingCartSize, LinkedList<Itemset>& totalItemsets);
void createShoppingCarts(Store &store, ShoppingCart *shoppingCarts);

void generateFrequentNItemsets(ShoppingCart* shoppingCarts, int shoppingCartSize, LinkedList<Itemset>& previousItemsets,
	LinkedList<Itemset>& nextItemsets, LinkedList<Itemset>& candidateItemsets, LinkedList<Itemset>& totalItemsets);

void generateFrequentOneItemsets(const Store& store, ShoppingCart* shoppingCarts, int shoppingCartSize, 
								 LinkedList<Itemset> &freqOneItemsets, LinkedList<Itemset>& totalItemsets);

void getFilename(string& inputFile, string& outputFile);
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