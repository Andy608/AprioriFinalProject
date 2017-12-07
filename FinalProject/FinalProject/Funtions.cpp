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

	if (inputStream.is_open())
	{
		string line;
		int lineNumber = 0;
		while (getline(inputStream, line))
		{
			stringstream lineStream(line);
			int itemID;

			while (lineStream >> itemID)
			{				
				shoppingCarts[lineNumber].addItemToCart(store.getItemByID(itemID));
			}


			lineNumber++;
		}
		cout << "Shopping carts populated!" << endl;
	}

	inputStream.close();
	
}


void getFilename(string& inputFile, string& outputFile)
{
	string Ifilename;
	string Ofilename;

	system("cls");

	cout << " Welcome to the Apriori Algorithim Program " << endl
		<< "//=======================================\\\\" << endl << endl;


	cout << "Enter the name of the dataset (include file ending). " << endl << "OR" << endl 
		 << "Enter 'exit' to quit the program." << endl;
	cin >> Ifilename;
	inputFile = Ifilename;

	if (inputFile == EXIT)
	{
		return;
	}

	cout << "Enter the name of the output (include file ending): ";
	cin >> Ofilename;
	outputFile = Ofilename;	
}


void generateFrequentOneItemsets(const Store& store, ShoppingCart* shoppingCarts, int shoppingCartSize, 
								 LinkedList<Itemset> &freqOneItemsets, LinkedList<Itemset>& totalItemsets)
{
	cout << "Generating Frequent-1 Itemsets...";

	Itemset temp;
	int i, j, k;
	int support, itemsetLength = 1;

	for (i = 0; i < store.getNumberOfItems(); ++i)
	{
		int *itemset = new int[itemsetLength];
		itemset[0] = store.getItemByIndex(i);
		support = 0;

		for (j = 0; j < shoppingCartSize; ++j)
		{
			for (k = 0; k < shoppingCarts->getNumberOfItems(); ++k)
			{
				if (itemset[0] == shoppingCarts[j].getItemAtIndex(k))
					support++;			
			}
		}

		if (support >= MINIMUM_SUPPORT)
		{
			temp = Itemset(itemset, 1);
			freqOneItemsets.insert(temp);
			totalItemsets.insert(temp);
		}

		
		delete[] itemset;
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
		nextItemsets.clear();
		itemsetLength++;

		cout << "Generating Frequent-" << itemsetLength << " Itemsets...";

		// Change from store to previous list of itemsets
		for (i = 0; i < previousItemsets.getCount(); ++i)
		{
			for (g = i + 1; g < previousItemsets.getCount(); ++g)
			{
				//candidate set
				Itemset itemsetI = previousItemsets.getData(i);
				Itemset itemsetG = previousItemsets.getData(g);
				Itemset::addNewItemsets(itemsetI, itemsetG, itemsetLength, candidateItemsets);
			}

			for (h = 0; h < candidateItemsets.getCount(); ++h)
			{
				currentItemset = candidateItemsets.getData(h);

				for (j = 0; j < shoppingCartSize; ++j)
				{
					supportCount = 0;

					for (k = 0; k < shoppingCarts[j].getNumberOfItems(); ++k)
					{
						//checking in shoppingcart against each item in the itemset
						for (f = 0; f < currentItemset.getSizeOfItemset(); ++f)
						{
							if (currentItemset.getItemAtIndex(f) == shoppingCarts[j].getItemAtIndex(k))
								supportCount++;
						}

						if (supportCount == currentItemset.getSizeOfItemset())
						{
							currentItemset.incrementSupport();
							supportCount = 0;
						}
					}
				}

				if (currentItemset.getSupport() >= MINIMUM_SUPPORT)
				{
					totalItemsets.insert(currentItemset);
					nextItemsets.insert(currentItemset);
				}
			}

			candidateItemsets.clear();
		}
		
		previousItemsets.clear();

		for (int i = 0; i < nextItemsets.getCount(); ++i)
		{
			previousItemsets.insert(nextItemsets.getData(i));
		}

		cout << " Done!!!!!!!!!" << endl;
	} while (!nextItemsets.isEmpty());
}


void apriori(const Store& store, ShoppingCart* shoppingCarts, int shoppingCartSize, LinkedList<Itemset>& totalItemsets)
{
	LinkedList<Itemset> freqOneItemsets;
	
	generateFrequentOneItemsets(store, shoppingCarts, shoppingCartSize, freqOneItemsets, totalItemsets);

	LinkedList<Itemset> previousItemsets = freqOneItemsets;
	LinkedList<Itemset> nextItemsets;
	LinkedList<Itemset> candidateItemsets;

	generateFrequentNItemsets(shoppingCarts, shoppingCartSize, previousItemsets, nextItemsets, candidateItemsets, totalItemsets);
}


void outputFrequentItemsets(LinkedList<Itemset> itemsetOutput, string& outputFilename)
{
	ofstream fout;
	string file = outputFilename;

	fout.open(file, ios::out);

	itemsetOutput.display(fout);
	
	fout.close();

	cout << "Itemsets successfully stored to file!" << endl;
}