#include "List.h"
#include <iostream>

// Lista dwukierunkowa

List::List()
{
	List::ListStart = NULL;
	List::ListEnd = NULL;
	List::asize = 0;
}

List::~List()
{
	free(List::ListStart);
	free(List::ListEnd);
}

void List::addToFront(int value)
{
	ListItem *tmp = new ListItem(value);
	if(tmp == NULL) return;
	if(List::ListStart == NULL)
	{
		List::ListStart = tmp;
		List::ListEnd = tmp;
	}
	else
	{
		List::ListStart->prev = tmp;
		tmp->next = List::ListStart;
		List::ListStart = tmp;
	}
	List::asize++;
}

void List::addToBack(int value)
{
	ListItem *tmp = new ListItem(value);
	if(tmp == NULL) return;
	if(List::ListEnd == NULL)
	{
		List::ListStart = tmp;
		List::ListEnd = tmp;
	}
	else
	{
		List::ListEnd->next = tmp;
		tmp->prev = List::ListEnd;
		List::ListEnd = tmp;
	}
	List::asize++;
}

void List::addToIndex(int value, int index)
{
	if(List::asize == 0) return;
	ListItem *tmp = new ListItem(value);
	ListItem *tmp2 = List::ListStart;
	ListItem *tmp3;
	for(int i=0;i<(index-1) &&tmp!=NULL;i++) tmp2 = tmp2->next;
	tmp3 = tmp2->next;
	tmp->prev = tmp2;
	if(tmp3 != NULL)
	{
		tmp->next = tmp3;
	}
	else List::ListEnd = tmp;
	if(tmp3 != NULL) tmp3->prev = tmp;
	tmp2->next = tmp;
	List::asize++;
}

void List::removeFromFront()
{
	List::ListStart = List::ListStart->next;
	List::ListStart->prev = NULL;
	List::asize--;
}

void List::removeFromBack()
{
	List::ListEnd = List::ListEnd->prev;
	List::ListEnd->next = NULL;
	List::asize--;
}

void List::removeFromIndex(int index)
{
	if(index > List::asize || List::asize == 0 || index < 0) return;
	ListItem *tmp = List::ListStart;
	if(index == 0)
	{
		List::ListStart = List::ListStart->next;
        List::ListStart->prev = NULL;
        List::asize--;
		return;
	}
	for(int i=0;i<index && tmp!=NULL;i++)
	{
		tmp = tmp->next;
	}
	if(tmp == NULL) return;
	if(tmp->next == NULL)
	{
		List::ListEnd = List::ListEnd->prev;
        List::ListEnd->next = NULL;
        List::asize--;
        return;
	}
	else
	{
		tmp->next->prev = tmp->prev;
		tmp->prev->next = tmp->next;
		List::asize--;
	}
}

void List::display()
{
	ListItem *tmp = List::ListStart;
	while(tmp != NULL)
	{
		std::cout << tmp->value << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;
}
