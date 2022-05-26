#ifndef HEAP_H
#define HEAP_H


class Heap
{
    public:
        Heap(int*arr, int length);
		Heap();
		virtual ~Heap();

		void createUp();
		void createDown();
		void add(int value);
		void deleteFromTop();
		void display();
		void display2();

    protected:

    private:
        int *head;
		int asize;
		int parentIndex(int index);
		int leftChildIndex(int index);
		int rightChildIndex(int index);
		void hswap(int index1, int index2);
		void fixUp(int index);
		void fixDown(int index);
};

#endif // HEAP_H
