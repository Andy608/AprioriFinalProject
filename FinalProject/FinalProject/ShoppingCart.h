
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

	int getNumberOfTransactions();
	void setNumberOfTransactions(int length);

	void addItemToCart(const int& item);
};





#endif // !SHOPPINGCART_H