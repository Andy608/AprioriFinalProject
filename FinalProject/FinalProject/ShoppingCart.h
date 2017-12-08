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