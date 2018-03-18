#include "AccountArray.h"
#include "BankingCommonDecl.h"

ACCOUNT_PTR& BoundCheckAccountPtrArray::operator[] (int idx)
{
	if (idx < 0 || idx >= len)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	else {
		return arr[idx];
	}
}

ACCOUNT_PTR BoundCheckAccountPtrArray::operator[] (int idx) const
{
	if (idx < 0 || idx >= len)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	else {
		return arr[idx];
	}
}