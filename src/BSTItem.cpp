#include "BSTItem.h"
#include <iostream>

using namespace std;

// Element drzewa poszukiwañ binarnych (BST) (pomocniczy)

BSTItem::BSTItem()
{
	int key = 0;
	BSTItem::left = NULL;
	BSTItem::right = NULL;
	BSTItem::parent = NULL;
}

BSTItem::~BSTItem()
{
	free(BSTItem::left);
	free(BSTItem::right);
	free(BSTItem::parent);
}
