#ifndef LIST_H
#define LIST_H
#include"ListItem.h"

class List
{
    public:
        List();
		virtual ~List();

		void addToFront(int value);
		void addToBack(int value);
		void addToIndex(int value, int index);
		void removeFromFront();
		void removeFromBack();
		void removeFromIndex(int index);
		int searchValue(int value); //return index
		void display();

    protected:

    private:
        ListItem *ListStart;
		ListItem *ListEnd;
		int asize;
};

#endif // LIST_H
