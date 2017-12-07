#include "header.h"


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


void generateFrequentOneItemsets(const Store& store, ShoppingCart* shoppingCarts, int shoppingCartSize, 
								 LinkedList<Itemset> &freqOneItemsets, LinkedList<Itemset>& totalItemsets)
{
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
	
	//tst
	//freqOneItemsets.display();
}


void generateFrequentNItemsets(ShoppingCart* shoppingCarts, int shoppingCartSize, LinkedList<Itemset>& previousItemsets, 
							   LinkedList<Itemset>& nextItemsets, LinkedList<Itemset>& candidateItemsets, LinkedList<Itemset>& totalItemsets)
{
	Itemset currentItemset;
	int supportCount, i, j, k;
	int itemsetLength = 1;

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
				Itemset itemsetI = previousItemsets.getData(i);
				Itemset itemsetG = previousItemsets.getData(g);
				Itemset::addNewItemsets(itemsetI, itemsetG, itemsetLength, candidateItemsets);
			}

			// { 1 }

			// { 1 1 2 2 }
			// { 1 2 6 }

			//candidateItemsets.display();

			for (int help = 0; help < candidateItemsets.getCount(); ++help)
			{
				currentItemset = candidateItemsets.getData(help);

				for (j = 0; j < shoppingCartSize; ++j)
				{
					supportCount = 0;

					for (k = 0; k < shoppingCarts[j].getNumberOfItems(); ++k)
					{
						//checking in shoppingcart against each item in the itemset

						for (int fuck = 0; fuck < currentItemset.getSizeOfItemset(); ++fuck)
						{
							//[] overloading the bracket operator to get the item at the index of 'fuck'

							/*if (currentItemset.getItemAtIndex(fuck) == 0 && shoppingCarts[j].getItemAtIndex(k) == 0 ||
							currentItemset.getItemAtIndex(fuck) == 756 && shoppingCarts[j].getItemAtIndex(k) == 756)
							{
							system("pause");
							}*/

							if (currentItemset.getItemAtIndex(fuck) == shoppingCarts[j].getItemAtIndex(k))
							{
								supportCount++;
								//break;
							}
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
				//delete[] itemset;
			}

			candidateItemsets.clear();
		}

		//nextItemsets.display();
		
		previousItemsets.clear();
		//previousItemsets = LinkedList<Itemset>(nextItemsets);

		for (int i = 0; i < nextItemsets.getCount(); ++i)
		{
			previousItemsets.insert(nextItemsets.getData(i));
		}

		previousItemsets.display();
		//system("pause");

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


void outputFrequentItemsets(LinkedList<Itemset> itemsetOutput)
{
	ofstream fout;
	string file = "output_apriori.txt";

	fout.open(file, ios::out);

	itemsetOutput.display(fout);
	
	fout.close();
}