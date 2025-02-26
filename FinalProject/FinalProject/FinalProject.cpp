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

#include "header.h"

int main()
{
	Store *store = new Store();
	ShoppingCart *shoppingCarts = nullptr;
	LinkedList<Itemset> itemsetOutput;
	
	int shoppingCartSize = 0;
	string iFileName;
	string oFileName;
	
	do
	{
		getFilename(iFileName, oFileName);
		
		if (iFileName != EXIT)
		{
			store->setStoreFileName(iFileName);

			if (store->createStore(shoppingCartSize))
			{
				shoppingCarts = new ShoppingCart[shoppingCartSize];
				createShoppingCarts(*store, shoppingCarts);

				apriori(*store, shoppingCarts, shoppingCartSize, itemsetOutput);
				
				outputFrequentItemsets(itemsetOutput, oFileName);

				delete[] shoppingCarts;
			}
		}
		
		system("pause");

	} while (iFileName != EXIT);

	delete store;
	return 0;
}