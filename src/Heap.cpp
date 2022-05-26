#include "Heap.h"
#include <iostream>

using namespace std;

// Kopiec binarny

Heap::Heap(int*arr, int length)
{
	Heap::asize = length;
	Heap::head = (int*)malloc(sizeof(int)*Heap::asize);
	for(int i=0;i<length;i++) Heap::head[i] = arr[i];
}

Heap::Heap()
{
	Heap::asize = 0;
	Heap::head = NULL;
}

Heap::~Heap()
{
	free(Heap::head);
}

int Heap::parentIndex(int index)
{
	return (index-1)/2;
}

int Heap::leftChildIndex(int index)
{
	return 2*index+1;
}

int Heap::rightChildIndex(int index)
{
	return 2*index+2;
}

void Heap::hswap(int index1, int index2)
{
	int tmp = Heap::head[index1];
	Heap::head[index1] = Heap::head[index2];
	Heap::head[index2] = tmp;
}

void Heap::fixUp(int index)
{
	while(index != 0)
	{
		if(Heap::head[parentIndex(index)] < Heap::head[index]) hswap(parentIndex(index), index);
		index = parentIndex(index);
	}
}

void Heap::fixDown(int index)
{
	if(leftChildIndex(index) <= Heap::asize && Heap::head[leftChildIndex(index) > Heap::head[index]])
	{
		hswap(leftChildIndex(index), index);
		fixDown(leftChildIndex(index));
	}
	if(rightChildIndex(index) <= Heap::asize && Heap::head[rightChildIndex(index) > Heap::head[index]])
	{
		hswap(rightChildIndex(index), index);
		fixDown(rightChildIndex(index));
	}
}

void Heap::createUp()
{
	for(int i=1;i<Heap::asize;i++) fixUp(i);
}

void Heap::createDown() // algorytm floyda
{
	for(int i=(Heap::asize-2)/2;i>=0;i--) fixDown(i);
}

void Heap::add(int value)
{
	if(Heap::asize == 0)
	{
		Heap::head = (int*)malloc(sizeof(int));
		Heap::asize++;
	}
	else
	{
		Heap::head = (int*)realloc(Heap::head,sizeof(int)*(++Heap::asize));
	}
	Heap::head[Heap::asize-1] = value;
	fixUp(Heap::asize-1);
}

void Heap::deleteFromTop()
{
	hswap(0,Heap::asize-1);
	Heap::head = (int*)realloc(Heap::head,sizeof(int)*(--Heap::asize));
	fixDown(0);
}

void Heap::display()
{
	for(int i=0;i<Heap::asize;i++) cout << Heap::head[i] << " ";
	cout << endl;
}

void Heap::display2()
{
	int nextLevel = 1;
	for(int i=0,j=1;i<Heap::asize;i++)
	{
		cout << Heap::head[i] << " ";
		if(j == nextLevel)
		{
			nextLevel*=2;
			cout << endl;
			j=0;
		}
		j++;
	}
}
