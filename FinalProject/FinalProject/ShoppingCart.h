
#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

class ShoppingCart
{

private:
	//Creates the variables for the shopping cart
	int *mTransaction;
	int mNumberOfItems;

public:
	/* Pre:		None
	*  Post:	Default constructor
	*  Purpose: Creates the default values for the objects
	*****************************************************************************/
	ShoppingCart();
	/* Pre:		None
	*  Post:	Default deconstructor
	*  Purpose: deletes all of the pointers in the object
	*****************************************************************************/
	~ShoppingCart();

	/* Pre:		None
	*  Post:	Gets the number of items in the shopping cart
	*  Purpose: Returns the number of items in the shopping cart to the program
	*****************************************************************************/
	int getNumberOfItems();
	/* Pre:		length of the shopping cart
	*  Post:	Sets the number of items of the shopping cart
	*  Purpose: Sets the number of shopping carts due to the length passed into it
	*****************************************************************************/
	void setNumberOfItems(int length);
	/* Pre:		the item index
	*  Post:	Gets the item at the index given
	*  Purpose: returns the item at the given index
	*****************************************************************************/
	const int& getItemAtIndex(int index) const;

	/* Pre:		the item int
	*  Post:	Adds the item to the cart
	*  Purpose: Adds the items to the cart
	*****************************************************************************/
	void addItemToCart(const int& item);
};

#endif // !SHOPPINGCART_H