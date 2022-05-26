#include "ListItem.h"
#include <iostream>

using namespace std;

// Element Listy (pomocniczy)

ListItem::ListItem(int val)
{
	ListItem::value = val;
	ListItem::prev = NULL;
	ListItem::next = NULL;
}

ListItem::ListItem()
{
	ListItem::value = 0;
	ListItem::prev = NULL;
	ListItem::next = NULL;
}

ListItem::~ListItem()
{
	free(ListItem::prev);
	free(ListItem::next);
}
