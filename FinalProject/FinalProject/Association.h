#ifndef ASSOCIATION_H
#define ASSOCIATION_H

#include "Itemset.h"

class Association
{
private:
	Itemset itemSet;
	int support;

public:
	Association();
	~Association();

	Itemset getitemSet();
	int getSupport();

	void setitemSet(Itemset set);
	void setSupport(int supportValue);

};

#endif // !ASSOCIATION_H