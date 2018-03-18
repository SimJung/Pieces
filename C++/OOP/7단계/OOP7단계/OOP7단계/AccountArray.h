#ifndef __ACCOUNTARRAY_H__
#define __ACCOUNTARRAY_H__

#include "Account.h"

typedef Account * ACCOUNT_PTR;

class BoundCheckAccountPtrArray
{
private:
	ACCOUNT_PTR *arr;
	int len;

public:
	BoundCheckAccountPtrArray(int l = 100) : len(l)
	{
		arr = new ACCOUNT_PTR[l];
	}

	ACCOUNT_PTR& operator[] (int idx);

	ACCOUNT_PTR operator[] (int idx) const;

	~BoundCheckAccountPtrArray() { delete[]arr; }
};

#endif
