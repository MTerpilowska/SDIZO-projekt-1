#ifndef ARRAY_H
#define ARRAY_H


class Array
{
    public:
        Array(int*arr, int length);
		Array();
		virtual ~Array();

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
        int *head;
		int asize;
};

#endif // ARRAY_H
