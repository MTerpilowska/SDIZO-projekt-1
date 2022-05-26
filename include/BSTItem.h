#ifndef BSTITEM_H
#define BSTITEM_H


class BSTItem
{
    public:
        int key;
		BSTItem *left;
		BSTItem *right;
		BSTItem *parent;

		BSTItem();
		virtual ~BSTItem();

    protected:

    private:
};

#endif // BSTITEM_H
