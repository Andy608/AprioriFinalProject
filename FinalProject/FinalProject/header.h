#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include "Association.h"
#include "Itemset.h"
#include "ShoppingCart.h"
#include "Store.h"


	void Apriori();
	void createShoppingCarts();


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