#ifndef LISTITEM_H
#define LISTITEM_H


class ListItem
{
    public:
        int value;
		ListItem* prev;
		ListItem* next;

		ListItem(int val);
		ListItem();
		virtual ~ListItem();

    protected:

    private:
};

#endif // LISTITEM_H
