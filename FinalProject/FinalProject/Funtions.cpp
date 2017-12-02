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