
#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

class ShoppingCart
{

private:

	int *mTransaction;
	int mNumberOfTransactions;

public:
	ShoppingCart();
	~ShoppingCart();

	int getNumberOfTransactions();
	void setNumberOfTransactions(int length);


};





#endif // !SHOPPINGCART_H