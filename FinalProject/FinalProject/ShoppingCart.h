
#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

class ShoppingCart
{

private:

	int *mTransaction;
	int mNumberOfItems;

public:
	ShoppingCart();
	~ShoppingCart();

	int getNumberOfItems();
	void setNumberOfItems(int length);
	const int& getItemAtIndex(int index) const;

	void addItemToCart(const int& item);
};





#endif // !SHOPPINGCART_H