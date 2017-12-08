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

void createShoppingCarts(Store &store, ShoppingCart *shoppingCarts)
{
	//Go into the store file.
	ifstream inputStream(store.getStoreFileName()); 

	//as long as the file can be opened
	if (inputStream.is_open())
	{
		string line;
		int lineNumber = 0;

		while (getline(inputStream, line))
		{
			stringstream lineStream(line);
			int itemID;

			//take in all of the items from the store by the id and set them to the shopping car as 
			//long as they are there
			while (lineStream >> itemID)
			{				
				shoppingCarts[lineNumber].addItemToCart(store.getItemByID(itemID));
			}

			//increase the line number which is also the index
			lineNumber++;
		}

		cout << "Shopping carts populated!" << endl;
	}

	inputStream.close();
}


void getFilename(string& inputFile, string& outputFile)
{
	string iFileName;
	string oFileName;

	system("cls");

	cout << " Welcome to the Apriori Algorithim Program " << endl
		<< "//=======================================\\\\" << endl << endl;

	cout << "Enter the name of the dataset (include file ending). " << endl << "OR" << endl 
		 << "Enter 'exit' to quit the program." << endl;

	cin >> iFileName;
	inputFile = iFileName;

	//if the user enters exit, the file will stop
	if (inputFile == EXIT)
	{
		return;
	}

	cout << "Enter the name of the output (include file ending): ";

	cin >> oFileName;
	outputFile = oFileName;
}


void generateFrequentOneItemsets(const Store& store, ShoppingCart* shoppingCarts, int shoppingCartSize, 
								 LinkedList<Itemset> &freqOneItemsets, LinkedList<Itemset>& totalItemsets)
{
	cout << "Generating Frequent-1 Itemsets...";

	//create vars
	Itemset currentItemset;
	int i, j, k;
	int itemsetLength = 1;

	//loops through as long as i is less than the store amount of items
	for (i = 0; i < store.getNumberOfItems(); ++i)
	{
		
		//assigning the itemset to an object in the store
		currentItemset = Itemset::itemToItemset(store.getItemByIndex(i)); 
		
		//as long as it is less than the shopping cart
		for (j = 0; j < shoppingCartSize; ++j)
		{
			for (k = 0; k < shoppingCarts[j].getNumberOfItems(); ++k)
			{
				//checks to see if the store itemset object is equal to the shopping carts objects
				//adds to the support
				if (currentItemset.getItemAtIndex(0) == shoppingCarts[j].getItemAtIndex(k))
					currentItemset.incrementSupport();
			}
		}

		//if the support is greater than the minumum support, add to the temporary itemset
		//then assign this value to the frequent and total itemsets
		if (currentItemset.getSupport() >= MINIMUM_SUPPORT)
		{
				
			freqOneItemsets.insert(Itemset(currentItemset));
			totalItemsets.insert(Itemset(currentItemset));
		}

	}

	cout << " Done!!!!!!!!!" << endl;
}


void generateFrequentNItemsets(ShoppingCart* shoppingCarts, int shoppingCartSize, LinkedList<Itemset>& previousItemsets, 
			LinkedList<Itemset>& nextItemsets, LinkedList<Itemset>& candidateItemsets, LinkedList<Itemset>& totalItemsets)
{
	Itemset currentItemset;
	int supportCount, i, j, k, g, h, f;
	int itemsetLength = 1;

	do
	{
		//clears the list
		nextItemsets.clear();
		itemsetLength++;

		cout << "Generating Frequent-" << itemsetLength << " Itemsets...";

		// Change from store to previous list of itemsets
		for (i = 0; i < previousItemsets.getCount(); ++i)
		{
			for (g = i + 1; g < previousItemsets.getCount(); ++g)
			{
				//creating candidate sets
				Itemset itemsetI = previousItemsets.getData(i);
				Itemset itemsetG = previousItemsets.getData(g);
				Itemset::addNewItemsets(itemsetI, itemsetG, itemsetLength, candidateItemsets);
			}

			//goes through until it reaches the end of the candidate itemsets
			for (h = 0; h < candidateItemsets.getCount(); ++h)
			{
				//gets the first current itemset
				currentItemset = candidateItemsets.getData(h);

				//goes through until it reaches the end of the shopping cart size
				for (j = 0; j < shoppingCartSize; ++j)
				{
					supportCount = 0;
					//goes through until it reaches the end of the items in the shopping cart
					for (k = 0; k < shoppingCarts[j].getNumberOfItems(); ++k)
					{
						//checking in shoppingcart against each item in the itemset
						for (f = 0; f < currentItemset.getSizeOfItemset(); ++f)
						{
							//if the current itemset and the item at that index is equal to the shopping cart, add to its support count
							if (currentItemset.getItemAtIndex(f) == shoppingCarts[j].getItemAtIndex(k))
							{
								supportCount++;
							}
						}

						//if the support is equal to the size of the curent itemset
						if (supportCount == currentItemset.getSizeOfItemset())
						{
							//increment the support of the current itemset
							currentItemset.incrementSupport();
							//restart the support count
							supportCount = 0;
						}
					}
				}

				//if the current itemset support is greater than the minimum support
				if (currentItemset.getSupport() >= MINIMUM_SUPPORT)
				{
					//add the items to the total itemsets and to the next itemset to be checked later
					totalItemsets.insert(Itemset(currentItemset));
					nextItemsets.insert(Itemset(currentItemset));
				}
			}

			//clear the candidate itemsets
			candidateItemsets.clear();
		}

		//clear the prevous itemsets
		previousItemsets.clear();

		//as long as i is less then the next itemsets length
		for (int i = 0; i < nextItemsets.getCount(); ++i)
		{
			//insert the passing itemsets to the previous itemsets
			previousItemsets.insert(nextItemsets.getData(i));
		}

		cout << " Done!!!!!!!!!" << endl;

		//do while the next itemset is not empty
	} while (!nextItemsets.isEmpty());

}


void apriori(const Store& store, ShoppingCart* shoppingCarts, int shoppingCartSize, LinkedList<Itemset>& totalItemsets)
{
	//create the variable and get the frequent one itemset
	LinkedList<Itemset> freqOneItemsets;
	
	generateFrequentOneItemsets(store, shoppingCarts, shoppingCartSize, freqOneItemsets, totalItemsets);

	//create the variables for all the other itemsets and get the frequent itemsets
	LinkedList<Itemset> previousItemsets = LinkedList<Itemset>(freqOneItemsets);
	LinkedList<Itemset> nextItemsets;
	LinkedList<Itemset> candidateItemsets;

	generateFrequentNItemsets(shoppingCarts, shoppingCartSize, previousItemsets, nextItemsets, candidateItemsets, totalItemsets);
}


void outputFrequentItemsets(LinkedList<Itemset> itemsetOutput, string& outputFilename)
{
	//output the frequent itemset
	ofstream fout;
	string file = outputFilename;

	fout.open(file, ios::out);

	itemsetOutput.display(fout);
	
	fout.close();

	cout << "Itemsets successfully stored to file!" << endl;
}