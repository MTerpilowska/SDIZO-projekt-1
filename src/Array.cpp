#include "Array.h"
#include <iostream>

using namespace std;

// Tablica dynamiczna

Array::Array(int*arr, int length)
{
	Array::head = arr;
	Array::asize = length;
}

Array::Array()
{
	Array::head = NULL;
	Array::asize = 0;
}

Array::~Array()
{
	free(Array::head);
}

void Array::addToFront(int value)
{
	if(Array::head == NULL || Array::asize == 0)
	{
		Array::head = (int*)malloc(sizeof(int));
		Array::head[0] = value;
		Array::asize++;
		return;
	}
	else
	{
		Array::head = (int*)realloc(Array::head,sizeof(int)*(++Array::asize));
		for(int i=Array::asize-1;i>0;i--)
		{
			Array::head[i] = Array::head[i-1];
		}
		Array::head[0] = value;
	}
}

void Array::addToBack(int value)
{
	if(Array::head == NULL || Array::asize == 0)
	{
		Array::head = (int*)malloc(sizeof(int));
		Array::head[0] = value;
		Array::asize++;
		return;
	}
	else
	{
		Array::head = (int*)realloc(Array::head,sizeof(int)*(++Array::asize));
		Array::head[Array::asize-1] = value;
	}
}

void Array::addToIndex(int value, int index)
{
	if(index > Array::asize-1 || index < 0) return;
	Array::head = (int*)realloc(Array::head,sizeof(int)*(++Array::asize));
	for(int i=Array::asize-1;i>index;i--)
	{
		Array::head[i] = Array::head[i-1];
	}
	Array::head[index] = value;
}

void Array::removeFromFront()
{
	if(Array::head != NULL && Array::asize > 1)
	{
		for(int i=0;i<Array::asize-1;i++)
		{
			Array::head[i] = Array::head[i+1];
		}
		Array::head = (int*)realloc(Array::head,sizeof(int)*(--Array::asize));
	}
	if(Array::asize == 1)
	{
		free(Array::head);
		Array::asize--;
	}
}

void Array::removeFromBack()
{
	if(Array::head != NULL && Array::asize > 1) Array::head = (int*)realloc(Array::head,sizeof(int)*(--Array::asize));
	if(Array::asize == 1)
	{
		free(Array::head);
		Array::asize--;
	}
}

void Array::removeFromIndex(int index)
{
	if(Array::head != NULL && Array::asize > 1 && index >= 0 && index < Array::asize)
	{
		for(int i=index;i<Array::asize-1;i++)
		{
			Array::head[i] = Array::head[i+1];
		}
		Array::head = (int*)realloc(Array::head,sizeof(int)*(--Array::asize));
	}
	if(Array::asize == 1 && index == 0)
	{
		free(Array::head);
		Array::asize--;
	}
}

void Array::display()
{
	for(int i=0;i<Array::asize;i++) cout << Array::head[i] << " ";
	cout << endl;
}
