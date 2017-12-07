#include "header.h"

const int MINIMUM_SUPPORT = 5;

void createShoppingCarts(Store &store, ShoppingCart *shoppingCarts)
{
	//Go into the store file.
	ifstream inputStream(store.getStoreFileName()); //Pass this in?

	if (inputStream.is_open())
	{
		//In a while loop that goes through the whole file.
		//Separate numbers by spaces
		//If a number comes up that is not in the list, append to the list.
		//End when end of file

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

//			shoppingCarts[lineNumber] = shoppingCart;

			lineNumber++;
		}
	}

	inputStream.close();
	
	cout << "Shopping carts populated!" << endl;
	system("pause");
}

string getFilename()
{
	string filename;

	system("cls");
	cout << "Enter the name of the dataset (include file ending): ";
	cin >> filename;

	return filename;
}

void apriori(const Store& store, ShoppingCart* shoppingCarts, int shoppingCartSize, LinkedList<Itemset>& totalItemsets)
{
	LinkedList<Itemset> freqOneItemsets;
	Itemset temp;
	int i, j, k;
	int support, itemsetLength = 1;
	for (i = 0; i < store.getNumberOfItems(); ++i)
	{
		int *itemset = new int[itemsetLength];
		itemset[0] = store.getItemByIndex(i);
		support = 0;

		// { 1 }

		// { 1 2 5 }
		// { 0 1 3 }

		for (j = 0; j < shoppingCartSize; ++j)
		{
			for (k = 0; k < shoppingCarts->getNumberOfItems(); ++k)
			{
				if (itemset[0] == shoppingCarts[j].getItemAtIndex(k))
				{
					support++;
					//break out when support is above minimum
				}
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

	/*LinkedList<Itemset> newFrequentItemset;
	itemsetLength++;

	for (int k = 0; k < freqOneItemsets.getCount(); k++)
	{
		for (int g = k; g < freqOneItemsets.getCount(); g++)
		{
			
			Itemset *itemset = new Itemset[itemsetLength];

			itemset[0] = freqOneItemsets.getData(k);
			itemset[1] = freqOneItemsets.getData(g);

			if (itemset[0] != itemset[1])
			{
				Itemset temp = Itemset(itemset, 2);
			}
		}
	}*/


	//////////////////////////////////
	

	LinkedList<Itemset> previousItemsets = freqOneItemsets;
	LinkedList<Itemset> nextItemsets;
	LinkedList<Itemset> candidateItemsets;
	Itemset currentItemset;
	itemsetLength = 1;

	do
	{
		nextItemsets.clear();
		itemsetLength++;

		// Change from store to previous list of itemsets
		for (i = 0; i < previousItemsets.getCount(); ++i)
		{
			for (int g = i + 1; g < previousItemsets.getCount(); ++g)
			{ 
				//candidate set
				Itemset::addNewItemsets(previousItemsets.getData(i), previousItemsets.getData(g), itemsetLength, candidateItemsets);
			}

			// { 1 }

			// { 1 1 2 2 }
			// { 1 2 6 }

			for (int help = 0; help < candidateItemsets.getCount(); ++help)
			{
				currentItemset = candidateItemsets.getData(help);

				for (j = 0; j < shoppingCartSize; ++j)
				{
					for (k = 0; k < shoppingCarts->getNumberOfItems(); ++k)
					{
						//checking in shoppingcart against each item in the itemset
						int supportCount = 0;

						for (int fuck = 0; fuck < currentItemset.getSizeOfItemset(); ++fuck)
						{
							//[] overloading the bracket operator to get the item at the index of 'fuck'
							if (currentItemset[fuck] == shoppingCarts[j].getItemAtIndex(k))
							{
								supportCount++;
								break;
							}
						}

						if (supportCount == currentItemset.getSizeOfItemset())
						{
							currentItemset.incrementSupport();
						}
					}
				}

				if (support >= MINIMUM_SUPPORT)
				{
					totalItemsets.insert(currentItemset);
					nextItemsets.insert(currentItemset);
				}
				//delete[] itemset;
			}

			candidateItemsets.clear();
		}

		previousItemsets = nextItemsets;
		previousItemsets.display();

	} while (!nextItemsets.isEmpty());
	



	//////////////////////////////////
























	/*if (freqOneItemsets[0].getItemset(contains(freqOneItemsets[1])))
	{

	}
	else
	{
		int itemset = new int[lengthofprevious + 1];
		itemset[0] = freq1itemset.getIdbyindex()
		itemset[1] = feq1itemset[1]

		temp = Itemset(itemset, length of previous set + 1);
		freqOneItemsets.insert()
	}*/

}